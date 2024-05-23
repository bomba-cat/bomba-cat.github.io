window.onload = function (){
    document.getElementById('firstframe').scrollIntoView({ behavior: 'smooth' });
}

document.getElementById('buttonup').style.display = 'none';

document.getElementById('buttondown').addEventListener('click', function() {
    document.getElementById('lastframe').scrollIntoView({ behavior: 'smooth' });
    document.getElementById('buttondown').style.display = 'none';
    document.getElementById('buttonup').style.display = 'block';
});
document.getElementById('buttonup').addEventListener('click', function() {
    document.getElementById('firstframe').scrollIntoView({ behavior: 'smooth' });
    document.getElementById('buttonup').style.display = 'none';
    document.getElementById('buttondown').style.display = 'block';
});