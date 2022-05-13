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
  .getElementById("xml-image")
  .setAttribute("src", doc.getElementsByTagName("img")[0].textContent);
