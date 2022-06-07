int uv_fs_open(uv_loop_t* loop, uv_fs_t* req, const char* path, int flags,
    int mode, uv_fs_cb cb) {
  int err;

  INIT(UV_FS_OPEN);
  err = fs__capture_path(req, path, NULL, cb != NULL);
  if (err) {
    SET_REQ_WIN32_ERROR(req, err);
    return req->result;
  }

  req->fs.info.file_flags = flags;
  req->fs.info.mode = mode;
  POST;
}