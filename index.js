var projectsbutton = document.getElementById("projectsbutton");
var aboutbutton = document.getElementById("aboutbutton");
var socialsbutton = document.getElementById("socialsbutton");

var about = document.getElementById("about");
var projects = document.getElementById("projects")
var socials = document.getElementById("socials");

projectsbutton.addEventListener("click", showProjects, true)
aboutbutton.addEventListener("click", showAbout, true);
socialsbutton.addEventListener("click", showSocials, true)

function showProjects() {
  projects.style.display = 'flex';
  about.style.display = 'none';
  socials.style.display = 'none';
}

function showAbout() {
  projects.style.display = 'none';
  about.style.display = 'inline';
  socials.style.display = 'none';
}

function showSocials() {
  projects.style.display = 'none';
  about.style.display = 'none';
  socials.style.display = 'block';
}
