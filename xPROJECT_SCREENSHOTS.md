---
permalink: /PROJECT_SCREENSHOTS/
---

<body>
  <h1>Project Screenshots:</h1>
  <p>Following are some screenshots taken from the project:</p>
  <button class="accordion"><b><i>1. WELCOME SCREEN</i></b></button>
  <div class="panel">
    <br>
    <img src="https://user-images.githubusercontent.com/66676402/88329102-e616a200-cd42-11ea-9223-b63647a9dc77.jpg">
    <hr>
  </div>
  
  <button class="accordion"><b><i>2. MAIN MENU</i></b></button>
  <div class="panel">
    <br>
    <img src="https://user-images.githubusercontent.com/66676402/88329241-13635000-cd43-11ea-97e4-bffc401b2f1c.jpg">
    <hr>
  </div>
  
 <button class="accordion"><b><i>3. DICE MENU</i></b></button>
  <div class="panel">
    <br>
    <img src="https://user-images.githubusercontent.com/66676402/88329704-d481ca00-cd43-11ea-8421-320f6bd25395.jpg">
    <hr>
  </div>
  
  <button class="accordion"><b><i>4. GAME BOARD & PLAYER STATS MENU</i></b></button>
  <div class="panel">
    <br>
    <img src="https://user-images.githubusercontent.com/66676402/88329340-368dff80-cd43-11ea-84b0-060ebbdc37d8.jpg">
    <hr>
  </div>
  
  <button class="accordion"><b><i>5. WIN MENU</i></b></button>
  <div class="panel">
    <br>
    <img src="https://user-images.githubusercontent.com/66676402/88333127-1bbe8980-cd49-11ea-8250-0b0481ff61cd.jpg">
    <hr>
  </div>
  
  <button class="accordion"><b><i>6. LOAD GAME MENU</i></b></button>
  <div class="panel">
    <br>
    <img src="https://user-images.githubusercontent.com/66676402/88329299-270eb680-cd43-11ea-9ef1-30311225b6cd.jpg">
    <hr>
  </div>
  
  <button class="accordion"><b><i>7. SAVE GAME MENU</i></b></button>
  <div class="panel">
    <br>
    <img src="https://user-images.githubusercontent.com/66676402/88329541-8ec50180-cd43-11ea-8086-733ac5dc45a3.jpg">
    <hr>
  </div>
  
  <button class="accordion"><b><i>8. HIDDEN SETTINGS</i></b></button>
  <div class="panel">
    <br>
    <img src="https://user-images.githubusercontent.com/66676402/88333274-604a2500-cd49-11ea-8ecc-502da434e9cd.jpg">
    <hr>
  </div>
  
  <button class="accordion"><b><i>9. GUIDE MENU</i></b></button>
  <div class="panel">
    <br>
    <img src="https://user-images.githubusercontent.com/66676402/88329383-4d345680-cd43-11ea-8990-4d2bd8c25164.jpg">
    <hr>
  </div>
   
  <script>
    var acc = document.getElementsByClassName("accordion");
    var i;

    for (i = 0; i < acc.length; i++) {
      acc[i].addEventListener("click", function() {
        this.classList.toggle("active");
        var panel = this.nextElementSibling;
        if (panel.style.maxHeight) {
          panel.style.maxHeight = null;
        } 
        else {
          panel.style.maxHeight = panel.scrollHeight + "px";
        } 
      });
    }
  </script>
  
</body>
