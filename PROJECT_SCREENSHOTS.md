---
permalink: /PROJECT_SCREENSHOTS/
---

<style> 
.mySlides {display: none;}
img {vertical-align: middle;}

/* Slideshow container */
.slideshow-container {
  max-width: 1000px;
  position: relative;
  margin: auto;
}

/* Next & previous buttons */
.prev, .next {
  cursor: pointer;
  position: absolute;
  top: 50%;
  width: auto;
  padding: 16px;
  margin-top: -22px;
  color: white;
  font-weight: bold;
  font-size: 18px;
  transition: 0.6s ease;
  border-radius: 0 3px 3px 0;
  user-select: none;
}

/* Position the "next button" to the right */
.next {
  right: 0;
  border-radius: 3px 0 0 3px;
}

/* On hover, add a black background color with a little bit see-through */
.prev:hover, .next:hover {
  color: rgba(127, 255, 212, 0.8);
  background-color: rgba(255, 255, 255, 0.4);
}

/* Caption text */
.text {
  color: #f2f2f2;
  font-size: 15px;
  padding: 0px 12px;
  position: absolute;
  bottom: 8px;
  width: 100%;
  text-align: center;
}

/* Number text (1/9 etc) */
.numbertext {
  color: #f2f2f2;
  background-color: rgba(0, 0, 0, 0.6);
  font-size: 12px;
  padding: 8px 12px;
  position: absolute;
  top: 0;
}

/* The dots/bullets/indicators */
.dot {
  cursor: pointer;
  height: 15px;
  width: 15px;
  margin: 0 2px;
  background-color: #bbb;
  border-radius: 50%;
  display: inline-block;
  transition: background-color 0.6s ease;
  text-decoration: none;
}

.active, .dot:hover {
  background-color: #717171;
  text-decoration: none;
}

/* Fading animation */
.fade {
  -webkit-animation-name: fade;
  -webkit-animation-duration: 1.5s;
  animation-name: fade;
  animation-duration: 1.5s;
}

@-webkit-keyframes fade {
  from {opacity: .4} 
  to {opacity: 1}
}

@keyframes fade {
  from {opacity: .4} 
  to {opacity: 1}
}

/* On smaller screens, decrease text size */
@media only screen and (max-width: 300px) {
  .prev, .next,.text {font-size: 11px}
}
</style>
<body>
  <h1 style="margin-top: 0px;">Project Screenshots</h1>
  <p>Following are some screenshots taken from the project:</p>
    
  <div class="slideshow-container">
  
  <div class="mySlides fade">
    <div class="numbertext">1 / 9</div>
    <img src="https://user-images.githubusercontent.com/66676402/88329102-e616a200-cd42-11ea-9223-b63647a9dc77.jpg" style="width:100%">
    <div class="text">WELCOME SCREEN</div>
  </div>
  
  <div class="mySlides fade">
    <div class="numbertext">2 / 9</div>
    <img src="https://user-images.githubusercontent.com/66676402/88329241-13635000-cd43-11ea-97e4-bffc401b2f1c.jpg" style="width:100%">
    <div class="text">MAIN MENU</div>
  </div>
  
  <div class="mySlides fade">
    <div class="numbertext">3 / 9</div>
    <img src="https://user-images.githubusercontent.com/66676402/88329704-d481ca00-cd43-11ea-8421-320f6bd25395.jpg" style="width:100%">
    <div class="text">DICE MENU</div>
  </div>
  
  <div class="mySlides fade">
    <div class="numbertext">4 / 9</div>
    <img src="https://user-images.githubusercontent.com/66676402/88329340-368dff80-cd43-11ea-84b0-060ebbdc37d8.jpg" style="width:100%">
    <div class="text">GAME BOARD & PLAYER STATS MENU</div>
  </div>
  
  <div class="mySlides fade">
    <div class="numbertext">5 / 9</div>
    <img src="https://user-images.githubusercontent.com/66676402/88333127-1bbe8980-cd49-11ea-8250-0b0481ff61cd.jpg" style="width:100%">
    <div class="text">WIN MENU</div>
  </div>
  
  <div class="mySlides fade">
    <div class="numbertext">6 / 9</div>
    <img src="https://user-images.githubusercontent.com/66676402/88329299-270eb680-cd43-11ea-9ef1-30311225b6cd.jpg" style="width:100%">
    <div class="text">LOAD GAME MENU</div>
  </div>
  
  <div class="mySlides fade">
    <div class="numbertext">7 / 9</div>
    <img src="https://user-images.githubusercontent.com/66676402/88329541-8ec50180-cd43-11ea-8086-733ac5dc45a3.jpg" style="width:100%">
    <div class="text">SAVE GAME MENU</div>
  </div>
  
  <div class="mySlides fade">
    <div class="numbertext">8 / 9</div>
    <img src="https://user-images.githubusercontent.com/66676402/88333274-604a2500-cd49-11ea-8ecc-502da434e9cd.jpg" style="width:100%">
    <div class="text">HIDDEN SETTINGS</div>
  </div>
  
  <div class="mySlides fade">
    <div class="numbertext">9 / 9</div>
    <img src="https://user-images.githubusercontent.com/66676402/88329383-4d345680-cd43-11ea-8990-4d2bd8c25164.jpg" style="width:100%">
    <div class="text">GUIDE MENU</div>
  </div>
  
  <a class="prev" onclick="plusSlides(-1)">&#10094;</a>
  <a class="next" onclick="plusSlides(1)">&#10095;</a>
  
  </div>
  <br>
  
  <div style="text-align:center">
    <span class="dot" onclick="currentSlide(1)"></span> 
    <span class="dot" onclick="currentSlide(2)"></span> 
    <span class="dot" onclick="currentSlide(3)"></span>
    <span class="dot" onclick="currentSlide(4)"></span> 
    <span class="dot" onclick="currentSlide(5)"></span> 
    <span class="dot" onclick="currentSlide(6)"></span>
    <span class="dot" onclick="currentSlide(7)"></span> 
    <span class="dot" onclick="currentSlide(8)"></span>
    <span class="dot" onclick="currentSlide(9)"></span>
  </div>

  <script>
  var slideIndex = 1;
  showSlides(slideIndex);
  
  function plusSlides(n) {
    showSlides(slideIndex += n);
  }
  
  function currentSlide(n) {
    showSlides(slideIndex = n);
  }
  
  function showSlides(n) {
    var i;
    var slides = document.getElementsByClassName("mySlides");
    var dots = document.getElementsByClassName("dot");
    if (n > slides.length) {slideIndex = 1}    
    if (n < 1) {slideIndex = slides.length}
    for (i = 0; i < slides.length; i++) {
        slides[i].style.display = "none";  
    }
    for (i = 0; i < dots.length; i++) {
        dots[i].className = dots[i].className.replace(" active", "");
    }
    slides[slideIndex-1].style.display = "block";  
    dots[slideIndex-1].className += " active";
  }
  </script>

</body>
