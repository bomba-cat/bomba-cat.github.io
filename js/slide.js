document.getElementById('buttondown').addEventListener('click', function() {
    document.getElementById('lastframe').scrollIntoView({ behavior: 'smooth' });
});
document.getElementById('buttonup').addEventListener('click', function() {
    document.getElementById('firstframe').scrollIntoView({ behavior: 'smooth' });
});