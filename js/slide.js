window.onload = function (){
    document.getElementById('firstframe').scrollIntoView({ behavior: 'smooth' });
    document.getElementById('buttonup1').style.display = 'none';
    document.getElementById('buttonup2').style.display = 'none';
    document.getElementById('buttondown2').style.display = 'none';
    document.getElementById('buttondown1').style.display = 'block';
}

window.addEventListener('resize', function(){
    document.getElementById('firstframe').scrollIntoView({ behavior: 'smooth' });
    document.getElementById('buttonup1').style.display = 'none';
    document.getElementById('buttonup2').style.display = 'none';
    document.getElementById('buttondown2').style.display = 'none';
    document.getElementById('buttondown1').style.display = 'block';
});

document.getElementById('buttondown1').addEventListener('click', function() {
    document.getElementById('secondframe').scrollIntoView({ behavior: 'smooth' });
    document.getElementById('buttondown1').style.display = 'none';
    document.getElementById('buttonup2').style.display = 'none';
    document.getElementById('buttondown2').style.display = 'block';
    document.getElementById('buttonup1').style.display = 'block';
});
document.getElementById('buttondown2').addEventListener('click', function() {
    document.getElementById('lastframe').scrollIntoView({ behavior: 'smooth' });
    document.getElementById('buttondown1').style.display = 'none';
    document.getElementById('buttondown2').style.display = 'none';
    document.getElementById('buttonup1').style.display = 'none';
    document.getElementById('buttonup2').style.display = 'block';
});
document.getElementById('buttonup1').addEventListener('click', function() {
    document.getElementById('firstframe').scrollIntoView({ behavior: 'smooth' });
    document.getElementById('buttonup1').style.display = 'none';
    document.getElementById('buttonup2').style.display = 'none';
    document.getElementById('buttondown2').style.display = 'none';
    document.getElementById('buttondown1').style.display = 'block';
});
document.getElementById('buttonup2').addEventListener('click', function() {
    document.getElementById('secondframe').scrollIntoView({ behavior: 'smooth' });
    document.getElementById('buttondown1').style.display = 'none';
    document.getElementById('buttonup2').style.display = 'none';
    document.getElementById('buttondown2').style.display = 'block';
    document.getElementById('buttonup1').style.display = 'block';
});