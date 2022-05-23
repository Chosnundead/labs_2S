function _readStringFromFileAtPath(pathOfFileToReadFrom) {
  var request = new XMLHttpRequest();
  request.open("GET", pathOfFileToReadFrom, false);
  request.send(null);
  var returnValue = request.responseText;

  return returnValue;
}

let string = _readStringFromFileAtPath("database/database.xml");

var parser = new DOMParser();
var doc = parser.parseFromString(string, "application/xml");

document
  .getElementsByClassName("xml-image")[0]
  .setAttribute("src", doc.getElementsByTagName("image")[0].textContent);
document
.getElementsByClassName("xml-image")[1]
  .setAttribute("src", doc.getElementsByTagName("image")[1].textContent);
document
.getElementsByClassName("xml-image")[2]
  .setAttribute("src", doc.getElementsByTagName("image")[2].textContent);
document
.getElementsByClassName("xml-image")[3]
  .setAttribute("src", doc.getElementsByTagName("image")[3].textContent);
document
.getElementsByClassName("xml-image")[4]
  .setAttribute("src", doc.getElementsByTagName("image")[4].textContent);
document
.getElementsByClassName("xml-image")[5]
  .setAttribute("src", doc.getElementsByTagName("image")[5].textContent);