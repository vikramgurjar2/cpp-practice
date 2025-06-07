 
  const { JSDOM } = require('jsdom');
  
  //class has two part one is state and other is behavior
  class Human{
    //properties
    

    //publically marked
    age=13;
    ht =5.56;
    #wt=66;//it is marked private can not be used outside the class

    
    constructor(newAge,newHeight){
        this.age = newAge;
        this.ht= newHeight;
    }
    //
    walking(){
        console.log("I am walking", this.#wt);

    }
    #running(){
        console.log("i am running");
    }
    get fetchweight(){
        return this.#wt;
    }
    set modfyWeight(val){
        this.#wt=val;
    }
  }
  let obj=new Human(50,190);
  console.log(obj.ht);
  obj.walking();

  //if we want to get the private data outside the class then 
  //u need to make a function called getters and setters inside class

  ////--->constructor-if u want to insert or initialise any value then constructor is used

  //default parameters---we can add default parameters  

function sayName(myName="Gurjar"){
    console.log("My name is ",myName );
}
sayName("Vikram");

function sayMyName(fName="Vikram",lName="Gurjar"){
    console.log("My name is",fName,lName);
}
sayMyName("Harsh");

//if u set the value null in default parameter then it will show the null valu3e
//but if u just set undefined then it will show the default value
console.log(Math.round(1.6));
console.log(Math.max(23,34,45,6,23,1,88));
let curr= new Date();
  console.log(curr.toString());
   
 

  ///Object clonning-->there are three ways 
//   1. using spread operator using{..}
//
let src={
    age:122,
    wt:45,
    ht:180,
};
let dest ={...src};

console.log("dest:",dest);
///2.Assingn method




let dst=Object.assign({},src);
console.log("dst:",dst);
//3. iteration mathod
let dist={};
 for(let key in src){
    let newKey =key ;
    let newKeyValue=src[key];
    dist[newKey]=newKeyValue;
 }


 console.log(dist);
 src.age=89;
 console.log("src:",src);
 /////

 // Garbage collector -->in c++ memory is freed mennually 
 //but in js a function is there for the memory free
 //we have no control over garbage collector it is run in the background automatically

 /////---------->Error Handling in javascript<-------------------------------
 //disruption in normal flow of execution
 //compile-time error--error before execution of error
 //run time error---occuring at the time of running
 //try catch log is used for error handling


 
//  try{

//     console.log("first line");
//     console.log("second line code");
//     //console.log(x);
//  }
//  catch(e){
//     //what u have to do with the error 
//     //retry logic
//     //logging 
//     //custom error
    
//     console.log("some error is there",e);
//  }
//  finally{
//     console.log("i will run what ever the condition be");
//  }

//  ///finally block-->it will run weather there is an error or not in the function 

// // lets create a custom error
// try{
//     console.log(x);

// }
// catch(e){
//     throw new Error("Bhai pehle declair kr lo");
    
// }


///document--> access-->id, class,tag,$0
///document->> update existing element---> innerHTML, outerHTML, text-content, innerText
///innerHTML--> u can do get and set value;
///for append element there is appendChild  ;
///fid.insertinnerhtml(position,element);
