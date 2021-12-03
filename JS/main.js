var fullName= 'Sang oc cho';
var age=26;
// alert(fullName);
// alert(age);


// console.log('day la snag nguuuuuu');

// confirm('xac nham ban tuoi');

// prompt('xac nham ban tuoi');

// setTimeout(function () {
//     alert('Thong bao');
// }, 5000 );

// setInterval(function () {
//     console.log('Day la log' + Math.random())
// }, 5000 );

// var a=1+2;
// var b=5;
// console.log(a);

// if(a>b)
// {
//     alert('Dung');
// }
// else{
//     alert('saiiiii');
// }


//LAM VIEC VOI CHUOI
var my_string ='hoc Js tại js jhzxjkbxz'
console.log(my_string.indexOf('Js'))
console.log(my_string.lastIndexOf('Js'))
console.log(my_string.search('Js'))
console.log(my_string.slice(4,6))
console.log(my_string.replace('Js','Java'))
console.log(my_string.replace(/Js/g,'JAAVA'))
console.log(my_string.toUpperCase())
console.log(my_string.toLowerCase())
console.log(my_string.trim())

var language='Javescript, PHP, Ruby'
console.log(my_string.split(', '))

console.log(my_string.charAt(1))

Number.isFinite(2 / 0); // false
Number.isFinite(20 / 5); // true
Number.isFinite(0 / 0); // false

Number.isInteger(999999999); // true
Number.isInteger(0.2);       // false
Number.isInteger(Math.PI);   // false

Number.parseFloat('10') // 10
Number.parseFloat('10.00') // 10
Number.parseFloat('238,21') // 238
Number.parseFloat('237.22') // 237.22
Number.parseFloat('34 56 78') // 34
Number.parseFloat(' 37 ') // 37
Number.parseFloat('18 is my age') // 18

Number.parseInt('10') // 10
Number.parseInt('10.00') // 10
Number.parseInt('238,21') // 238
Number.parseInt('237.22') // 237
Number.parseInt('34 56 78') // 34
Number.parseInt(' 37 ') // 37
Number.parseInt('18 is my age') // 18

var numberObject = 1234.56789;

numberObject.toFixed(); // '1235'
numberObject.toFixed(1); // '1234.6'
numberObject.toFixed(6); // '1234.567890'

(11).toString();    // '11'
(18).toString();     // '18'
(17.3).toString();   // '17.3'

//MẢnng

var vinh=[
    'vhshdjdb',
    'sạbjkbsajkbsa',
    'sạvkaskvsa'
];

console.log(vinh.toString())
console.log(vinh.join())
console.log(vinh.join(''))
console.log(vinh.pop())
console.log(vinh.push('dark0'))
console.log(vinh.shift())
console.log(vinh.unshift('dark '))
console.log(vinh.splice(1,1)) //xoa
console.log(vinh.splice(1,0,'DAtttt'))


var sang=[
    'nooo',
    'sakasbjksab'
]
console.log(vinh.concat(sang))
console.log(vinh.slice(1,2))


// Tạo đối tượng date ứng với thời gian hiện tại
new Date()

// Tạo đối tượng date ứng với đối số truyền vào
new Date(milliseconds)
new Date(date string)
new Date(year, month, day, hours, minutes, seconds, milliseconds)

// Lấy timestamp hiện tại
let timestamp = Math.floor(Date.now() / 1000)

// hoặc
const date = new Date()
timestamp = Math.floor(date.getTime() / 1000)

// hoặc
timestamp = Math.floor(+ new Date() / 1000)

// Lấy timestamp mốc thời gian cụ thể
const date = new Date('00:00:00 01/01/2021')
timestamp = Math.floor(date.getTime() / 1000)

// hoặc
timestamp = Math.floor(+ new Date('00:00:00 01/01/2021') / 1000)

//Lay value Object
let myObject = {
    firstName: 'Nam',
    lastName: 'Truong',
    age: 21,
    text: 'tuoi'
}

for (let key in myObject) {
    console.log(myObject[key])
}
//Lay tung chu cai
let language = "Javascript";

for (let _key2 in language) {
    console.log(language[_key2]);
}




-apply with array:
var languages = [
    'javarscript',
    'react',
    'Nodejs'
];
for(var value of languages)
{
console.log(value);
}
--apply with string:
var myString = 'hello';
for(var value of myString) //lay characters in string
{
console.log(value);
}
--apply with object:
var myInfo = {
    name: 'Long Yonkou',
    age: '20'
}
    for(var value of Object.keys(myInfo)){ // lay value in key of object
        console.log(myInfo[value]);
}
var myInfo = {
    name: 'Long Yonkou',
    age: '20'
}
    for(var value of Object.value(myInfo)){ // lay value in object
        console.log(value);
}


--key Break(thoát khỏi vòng lặp khi đúng điều kiện)
for(var i = 0; i < 1000; i++) {
  if(i % 2 == 0) {
    break;
}
OUTPUT: Nothing bởi vì 0 % 2 == 0 nó break luôn.
--key continue (bỏ qua khi đúng điều kiện)
for(var i = 0; i < 1000; i++) {
  if(i % 2 == 0) {
    continue;   
    }
}
OUTPUT: Nó sẽ lấy các số lẻ bởi vì điều kiện là chia hết cho 2 thì sẽ bỏ qua.


//map
var arr= courses.map
