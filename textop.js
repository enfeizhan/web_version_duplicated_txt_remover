$(document).ready(function(){
  $("#submit").click(function(){
    var textContent = $("#textinput").val();
    var previousWord = "";
    var presentWord = "";
    var textOutput = "";
    for (var i = 0; i < textContent.length; i++)
    {
      if (textContent[i] == " ")
      {
	//detect a new word in text
	if ( presentWord != previousWord)
	{
	  // non-double-typing
	  textOutput = textOutput + presentWord + " ";
	  previousWord = presentWord;
	  presentWord = "";
	}else
	{
	  // double-typing
	  var removeConfirm = confirm("Remove the double-typed word \"" + presentWord +"\" in \"" + previousWord + " " + presentWord + "\"?");
	  if (removeConfirm == true)
	  {
	    presentWord = "";
	    // yes I wanna remove the duplicated text
	  } else {
	    // no 
	    textOutput = textOutput + presentWord + " ";
	    previousWord = presentWord;
	    presentWord = "";
	  }	  
	}
      }else if (textContent[i] == "\n")
      {
	// newline character also detects a new word
	if ( presentWord != previousWord)
	{
	  // non-double-typing
	  textOutput = textOutput + presentWord + "\n";
	  previousWord = presentWord;
	  presentWord = "";
	}else
	{
	  // double-typing
	  textOutput = textOutput + "\n";
	  presentWord = "";
	}	
      }else
      {
	// no new word detected, keep receiving new characters to form a word
	presentWord = presentWord + textContent[i];
      }
    }
    if ( presentWord != previousWord)
    {
      textOutput = textOutput + presentWord;
    // add the last word
    }
    $("#textoutput").text(textOutput);
  });
}); 
