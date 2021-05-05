let button = document.getElementById('button');
let text = document.getElementById('text');
let c = 0;
function show(){
    if(c%2===0){
        text.innerHTML = 'น๊านแนะะะ';
    }else{
        text.innerHTML = '';
    }
    c++;
    
}

button.addEventListener('click' , show);
