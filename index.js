const { JSDOM } = require('jsdom');

// Create a simulated DOM
const dom = new JSDOM(`
  <!DOCTYPE html>
  <html>
    <body>
      <div id="fid">Original Content</div>
    </body>
  </html>
`);

// Access the simulated document
const document = dom.window.document;

// Select the element
let myDiv = document.querySelector('#fid');
const newelement = '<p>New Paragraph</p>';

// Insert new element before the target
myDiv.insertAdjacentHTML('beforebegin', newelement);

// Output the updated HTML
console.log(dom.serialize());
console.log(newelement);
document.addEventListener("DOMContentLoaded", () => {
    let myDiv = document.querySelector('#fid');
    const newElement = '<p>New Paragraph</p>';
    myDiv.insertAdjacentHTML('beforebegin', newelement);
});

// let car = ['lambo', 0, "vikram", 0.25];

// for (var i = 0; i < 7; i++) {
//     console.log(car[i]);
// }
// let age = 24;
// let statu = (age >= 24) ? 'I can vote' : 'i cannot vote';
// console.log(statu);
// let num = 4;
// switch (num) {
//     case 1: console.log('A');
//         break;
//     case 2: console.log('B');
//         break;
//     case 3: console.log('C');
//         break;
//     case 4: console.log('D');
//         break;
//     case 5: console.log('E');
//         break;
//     case 6: console.log('F');
//         break;
//     default: console.log('G');
//         break;
// }

// //for loop
// //same as c++;
// for (let i = 0; i < 7; i++) {
//     console.log("vikram");
// }
// let first = "vikram";
// let second = "singh";
// let names = `${first} and  ${second}`;
// console.log(names);
// console.log(names.toUpperCase());
// console.log(names.substring(2, 9));
// console.log(names.split(2, 9));
// let words = names.split(' ');
// console.log(words);
// console.log(words.join(','));
// //what is a function
// //  Function it is
// function myname(){
//     console.log("this is function");
// }
// myname();
// //return functiobn=
// function retfuc(num){
//     return "this is me";
// }
// var a=retfuc(4);
// console.log(a);
// // arrow function
// //variable function
// let getext= (x,y)=> {
//     let ans=x**y;
//     return ans ;
// }
//var k=getext(5,7);
//console.log(k);

//object
let obj = {
    names:"vikram",
    age: 22,
    height:"5feet 10inch",
    greet: function(){
        console.log("hello how are you guys");
    }
}
obj.greet();
///interview question shallaw copy and deep copy
///arrays--it is collection of items it is type of list
// push- array.push(7);
//shift- remove leftmost elemet
// unshift --add element in leftmost side
///slice-array.slice(2,4); remove the element from index 2 to index 3
//splice  array.splice(1,2,"vikram")  remove two element fromm index 1 and put vikram at index 1
let arr=[1,2,3,4,5,6];
arr.splice(1,3,"vikram");
console.log(arr);
arr[1]=2;
arr.map((number,index)=>{
    console.log(number);
    console.log(index);
})
//filter--the data will be filter out it contain a function which decide weather it should be included or excluded
let evenarray= arr.filter((number)=>{
    return number%2==0;
});
console.log(evenarray);
//reduce
 
let arra= [1,34,4,0,43,7,8,9];
let anser= arra.reduce((acc,cur)=>{
    return  acc+cur;
},0);
console.log(anser);
arra.sort();
console.log(arra);


arra.forEach((value,index)=>{
    console.log("Number:",value,"index:",index);
})

for(let key in obj){
    console.log(key," ",obj[key]);
}
//for of loop
//let arr =[12,23,44,67,78];
//arrays with functions
function getsum(arr){
    let len=arr.length;
    let sum=0
}


///function hosting -- function shift to the top of current scope so if you are 
//variable hosting --variable declaration will move to above of current scope but will be undefinded
//let and const can not move to top 
class Human {

}
const object1= new Human;
//class can not be hosted to top

///global scope-- we can use var let const at any place if globally set
//if var in the between blocks it can also be used outside the blocks
//it is block-
//what html content would u like to add in the aray



{
    var age=9;
}
console.log(age);




