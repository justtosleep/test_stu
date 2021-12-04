let myImage = document.querySelector('img');

myImage.onclick = function() {
    let mySrc = myImage.getAttribute('src');
    if(mySrc === 'images/image1.jpg') {
      myImage.setAttribute('src', 'images/image2.webp');
    } else {
      myImage.setAttribute('src', 'images/image1.jpg');
    }
}

let myButton = document.querySelector('button');
let myHeading = document.querySelector('h1');

function setUserName() {
    let myName = prompt('请输入你的名字。');
    if(!myName || myName === null) {
        setUserName();
    } else {
        localStorage.setItem('name', myName);
    myHeading.textContent = '5t5向您致以诚挚问候，' + myName;
    }
  }

  if(!localStorage.getItem('name')) {
    setUserName();
  } else {
    let storedName = localStorage.getItem('name');
    myHeading.textContent = '5t5向您致以诚挚问候，' + storedName;
  }

  myButton.onclick = function() {
    setUserName();
 }