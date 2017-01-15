function remove() {
    var textContent = document.getElementById("textinput").value;
    var previousWord = "";
    var presentWord = "";
    var textOutput = "";
    var words = textContent.split(" ")
    var res = [];
    var cleanedWord = "";
    var wordsLength = words.length;
    for (i = 0; i < wordsLength; i++){
        presentWord = words[i];
        cleanedWord = presentWord.replace("\n", "");
        if (cleanedWord == previousWord) {
	        // double-typing
	        var removeConfirm = confirm(
                "Remove the double-typed word \""
                + presentWord 
                +"\" in \"" 
                + previousWord 
                + " " 
                + presentWord 
                + "\"?"
            );
	        if (removeConfirm == true){ }
            else {
                res.push(presentWord);
	        }	  
        } else{
            res.push(presentWord);
            previousWord = presentWord;
        }

    }
    textOutput = res.join(" ");
    document.getElementById("textoutput").innerHTML = textOutput;
}
