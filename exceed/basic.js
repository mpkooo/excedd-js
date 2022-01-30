//Variable
//let,const,var
let a;
a='Hi';
console.log(a);

const h = 100;

//naming convention

//data types
let o = null;
let u = undefined; //young mai dai value
let mystring = 'broccoli';
let num = 7;
let mybool = true;
let myarr = [1,'n',false,[3,'7']];
let obj = {name: 'mint', age: 19, isstudent: true};
let num2 = 7+7+1

// ===, !==

const result = 10%2 === 0 ? 'even' : 'odd';
console.log(result);

const veggie = ['broccoli','pumpkin'];

console.log(veggie.length);
console.log(veggie[1]);

veggie.push('potato');
console.log(veggie);
console.log(veggie.length);

//veggie.splice(0,2);
console.log(veggie);

//loop
for (let i=0;i<veggie;i++)
    {console.log(veggie[i]);}

for (const v of veggie)
    {console.log(v);}

//string cincatenating
const myname = 'mint';
const g1 = 'hi' + myname;
const g2 = `hi, ${myname}`;
console.log(g2);

/*
//function
function add(n1,n2)
    {return n1+n2;}

console.log(add(3,7));

const add2 = (n1,n2)
    {return n1+n2;}

console.log(add2(4+4));
*/

//callback function
function greeting(callback)
{
    callback('ohayou')
}
function logGreeting(morning)
{
    console.log('Hello',morning);
}

greeting(logGreeting);


//obj
const dog =
{
    name: 'Sho',
    age: '7',
    bark()
        {console.log('woooooofffff!!!');},
    introduce()
        {console.log(`i am ${this.name}`);}
}

console.log(dog.name);
dog.bark();
dog.introduce();

dog.age = 10;
console.log(dog.age);

dog.breed = 'Golden retriever';
console.log(dog.breed);

const me = 
{
    name: 'mint',
    year: 2,
    age: 19,
    isstudent: true,
    introduce()
        {console.log(`ohayou my name is ${this.name}`);}
}
console.log(me.introduce);


//deconstruct
const d1 = [1,2,3,4,20];
const d2 = {str: 'hi', n:2, bool:false, arr: [1,2,3,4]}

const [a1,a2,a3,...rest] = d1;
console.log(a1);
console.log(a2);
console.log(rest);

const {bool,str, ...rest2} = d2;
console.log(bool);
console.log(str);
console.log(rest2);

const std=
[
    {
        id: 1,
        thename: 'finn',
        age: 10,
    },
    {
        id: 2,
        thename: 'jaeden',
        age: 20,
    },
    {
        id: 3,
        thename: 'wyatt',
        age: 30,
    }
];

std.forEach(function (u)
    {console.log(u.id);});

const userwithid3 = std.find((std) => std.id === 3);
console.log(userwithid3);

const indexofjd = std.findIndex((std) => std.thename === 'jaeden');
console.log(indexofjd);

const adults =  std.filter((std) => std.age >= 20);
console.log(adults);

const usernamelist = std.map((std) => std.thename)
console.log(usernamelist);

//find finn's obj
const findfinn = std.find((std) => std.thename === 'finn');
console.log(findfinn);

//changing into array that store obj of each one except id
const newuserlst = std.map(({thename,age}) =>
    { return {thename,age}};
console.log(newuserlst);

//create method that obj of each one can introduce themself
std.forEach(std) =>
{
    std.greeting = function()
    {
        console.log(`hello, i'm ${this.thename}`);
    }
}
user[1].greeting();