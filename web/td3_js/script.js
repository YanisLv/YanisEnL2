//1.1

var intro = document.querySelector(".intro h2");
intro.textContent = "Bon matin ! Découvrez les films du moment";
var dateCourante = new Date();
var heure = dateCourante.getHours();
if(heure<12){
    intro.textContent = "Bon matin ! Découvrez les films du moment";
}
else if(12<=heure && heure <= 18){
    intro.textContent = "Bon après-midi ! Envie d'une séance cinéma ?";
}
else{
    intro.textContent = " Bonsoir ! C'est l'heure idéale pour un bon film"
}

//1.2

var fic = window.location.pathname;
var nav_a = document.querySelectorAll("nav a");
nav_a.forEach((elem) =>{
    console.log(fic);
    console.log(elem.getAttribute("href"));
    if(fic.includes(elem.getAttribute("href"))){
        elem.classList.add(".active");
        elem.style.color = "red";
    }
});

//1.3

var fc = document.querySelectorAll(".film-card");
fc.forEach(card =>{
    card.addEventListener("click", (event) => {
        card.classList.toggle("film-selected");
    });
});

//2.1
const parent = document.querySelector(".films-section")
const ref = parent.querySelector(".films-grid");
const p = document.createElement("p");
const cpt = document.querySelectorAll('.film-selected').length;
p.id = "compteur";
p.textContent = `${cpt} film(s) sélectionné(s)`;
//parent.appendChild(p);
parent.insertBefore(p,ref);


fc.forEach(card =>{
    card.addEventListener("click", (event) => {
        const cpt = document.querySelectorAll('.film-selected').length;
        p.textContent = `${cpt} film(s) sélectionné(s)`;
    });
});

//2.2

const rech = document.getElementById("recherche");
rech.addEventListener()
