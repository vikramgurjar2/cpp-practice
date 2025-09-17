// Create three promises that resolve after different times
const fastPromise = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve('Fast promise resolved');
    }, 1000);
});

const mediumPromise = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve('Medium promise resolved');
    }, 2000);
});

const slowPromise = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve('Slow promise resolved');
    }, 3000);
});

// Use Promise.race to return the first resolved promise
Promise.race([fastPromise, mediumPromise, slowPromise])
    .then((message) => {
        console.log('First resolved promise:', message);
    })
    .catch((error) => {
        console.error('Promise rejected:', error);
    });







let promise = new Promise(function(resolve,reject){

    setTimeout(function(){
        console.log("promise is resolved");
        resolve("promise 1 resolved");

    },2000);
})

promise.then(function(){
    console.log("I am in then block");
})

new Promise((resolve , reject)=>{
    setTimeout(()=>{
        console.log("promise 2 is resolved");
        resolve();
    },3000);
}).then(()=>{
    console.log("I am in then block of promise 2");
})
/////third promise
const thirdpromise = new Promise((resolve,reject)=>{
    setTimeout(()=>{
        console.log("promise 3 is resolved");
        resolve({username:"vikram",email:"vikram@gmail.com"});
    },4000);
})

thirdpromise.then((data)=>{
    console.log("I am in then block of promise 3");
    console.log(data);
})

//////promise chaining promise4

const promise4 =new Promise((resolve,reject)=>{
    setTimeout(()=>{
         let error=false;
         if(error){
            reject("Error: Something went wrong!");
         }
         else{
            resolve({username:"john",email:"john@gmail.com"});
         }
    },5000);

})
promise4.then((data)=>{
    return data.username;
}).then((username)=>{
    console.log(username);
})
.catch((error)=>{
    console.error(error);   
})
.finally(()=>{
    console.log("This will always execute, regardless of success or failure.");
})

////will use async await

const promise5 =new Promise((resolve,reject)=>{
    setTimeout(()=>{
         let error=true;
         if(error){
            reject("Error: Something went wrong!");
         }
         else{
            resolve({username:"john",email:"john@gmail.com"});
         }
    },1000);

})

Promise.all([promise, thirdpromise, promise4])
    .then((messages)=>{
        console.log("all promises are resolved");
        messages.forEach((message,index)=>{
            console.log(`promise ${index+1}: ${message} `);
        })
       .catch((error) => {
        console.error('One of the promises rejected:', error);
    });  
    })



async function usepromise(){
    try{
        const response= await promise5;
        console.log(response.username+" using async await");

    }
    catch(error){
        console.log(error+" using async await");
    }
}


usepromise();

fetch("https://jsonplaceholder.typicode.com/posts")
.then((res)=>{
    return res.json();
})
.then((data)=>{
   console.log(data);
})
.catch((errot)=>
console.log(error));

