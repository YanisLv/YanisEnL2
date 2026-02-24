/*var intro = document.querySelector(".intro h2");
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
    */
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