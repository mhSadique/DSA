// method 01
function reverseString(str) {
    if (!str || str.length < 2 || typeof str !== 'string') {
        return 'Please, give me a string';
    }
    const strArr = str.split('');
    const strArrReversed = [];
    for (let i = 0; i < strArr.length; i++) {
        const item = strArr[strArr.length - (i + 1)];
        strArrReversed.push(item);
    }
    return strArrReversed.join('');
}

// method 02
function reverseString2(str) {
    if (!str || str.length < 2 || typeof str !== 'string') {
        return 'Please, give me a string';
    }
    const reversed = [];
    const lastIndex = str.length - 1;
    for (let i = lastIndex; i >= 0; i--) {
        reversed.push(str[i]);
    }
    return reversed.join('');
}

console.log(reverseString('sadique'));
console.log(reverseString2('euqidas'));