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

//call back
function getuserbyid(id,cb)
{
    console.log('Starting operation...');

    //Simulate network call
    setTimeout(() =>
    {
        console.log('Finding std...')
        const user = std.find((std) => std.id === id);
        console.log('operation ended');

        if (user)
            {cb(null,user);}
        else
            {cb('user not found',null)}
    }, 1500)
}

const user = getuserbyid(1,(error,user) => console.log(error,user));
console.log(user);

//promise
async function getuserbyid2(id)
{
    return new Promise((resolve, reject) => {

    console.log('Starting operation...');

    //Simulate network call
    setTimeout(() =>
    {
        console.log('Finding std...')
        const user = std.find((std) => std.id === id);
        console.log('operation ended');

        if (user)
            {resolve(user);}
        else
            {reject('user not found')}
    }, 1500)
    });
}

getuserbyid2(4)
    .then((std) => console.log(std))
    .catch((error) => console.log(error));




(async function()
{
    try 
    {
        const user = await getuserbyid2(7);
        console.log(user);
    }    
    catch (error)
    {console.log(error);}
})();

