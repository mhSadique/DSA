static ssize_t uv__fs_open(uv_fs_t* req) {
#ifdef O_CLOEXEC
  return open(req->path, req->flags | O_CLOEXEC, req->mode);
#else  /* O_CLOEXEC */
  int r;

  if (req->cb != NULL)
    uv_rwlock_rdlock(&req->loop->cloexec_lock);

  r = open(req->path, req->flags, req->mode);

  /* In case of failure `uv__cloexec` will leave error in `errno`,
   * so it is enough to just set `r` to `-1`.
   */
  if (r >= 0 && uv__cloexec(r, 1) != 0) {
    r = uv__close(r);
    if (r != 0)
      abort();
    r = -1;
  }

  if (req->cb != NULL)
    uv_rwlock_rdunlock(&req->loop->cloexec_lock);

  return r;
#endif  /* O_CLOEXEC */
}