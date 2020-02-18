const axios = require("axios");
let one = "";
let two = "";
let ab = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

const call = async (s) => {
  try {
    let a = await axios.post(s);
    console.log(s)
    return a
} catch (error) {
    return ""
  }
};

async function run() {
    for (let i = 0; i < 26; i++) {
      one = ab[i];
      for (let j = 0; j < 26; j++) {
        two = ab[j];
              for (let k = 0; k < 26; k++) {
        three = ab[k];
              for (let l = 0; l < 26; l++) {
        four = ab[l];
//        console.log(`${one}${two}`)
        ln=`https://www.hackerrank.com/contests/${one}${two}${three}${four}`
        let s = await call(ln);
              }
      }
    }
}
}
run();

