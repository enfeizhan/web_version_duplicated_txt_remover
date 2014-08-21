// detect and eliminate double typing
#include <iostream>
#include <fstream>
#include <string>




int main()
{
  using namespace std; 
  
  cerr << "Text double-typing remover version 1.0\n"
       << "Copyright (c) Fei Zhan 2013-2014 All Rights Reserved\n"
       << "No warranty\n"
       << "For license conditions email f.zhan@uq.edu.au\n";
  ifstream fin;
  string filename;
  cout << "Enter file name for proof reading:\n";
  cin >> filename;
  fin.open(filename.c_str());
  while (!fin.is_open()) 
  {
    cerr << "Fail to open file " << filename << ", please check the name of intended file." << endl;
    cout << "Enter file name for proof reading:\n";
    cin >> filename;
    fin.open(filename.c_str());
  }
  ofstream flog;
  string logfilename;
  logfilename = filename + ".log";
  flog.open(logfilename.c_str());
  ofstream fout;
  fout.flush();
  cout << "Enter file name for proof reading result:\n";
  cin >> filename;
  fout.open(filename.c_str());
  
  string word1_str;
  string word2_str;
  string word3_str;
  string yesno;
  char letter;
  char letter0;
  char end[5];
  string end_str;
  bool math_flag = false;
  


  int dup_wd_num = 0;
  int line_num = 1;
  int wd_num_line = 0;
  
  
  // count the number of duplicated words

  
  while (fin.get(letter))
  {
    
//     if (word1_str == "\\begin{")
//     {
//       math_flag == true;
//       end[0] = end[1];
//       end[1] = end[2];
//       end[2] = end[3];
//       end[3] = end[4];
//       fin.get(end[4]);
//       end_str = end;
//       if (end_str == "\\end{")
//       {
// 	math_flag == false;
// 	word1_str.clear();
//       }
//       continue;
//     }
    
    
    
    
    if(letter == ' ') // end of a word but not at the end of a line
    {    
      if (word1_str == word2_str) //same as the word before
      {
	wd_num_line++; //one more word counted
	cerr << "Double-typing spotted:\n" // report and ask if delete double-typing
	     << "\"" << word3_str << "\" \"" << word2_str << "\" \"" << word1_str << "\"" << endl
	     << "Do you reckon this is a double-typing and want to delete it?\n"
	     << "Choose yes or no:";
	cin >> yesno;
	while (yesno != "yes" && yesno != "y" && yesno != "Y" && yesno != "no" && yesno != "n" && yesno != "N")
	{
	  cerr << "Choose yes or no:";
	  cin >> yesno;
	}
	if (yesno == "yes" || yesno == "y" || yesno == "Y")
	{
	  dup_wd_num++; // one more double-typing
	  wd_num_line--; // one fewer word counted
	  flog << "Double-typing spotted in line " << line_num << ": \n"
	       << "\"" << word3_str << "\" \"" << word2_str << "\" \"" << word1_str << "\"" << endl
	       << word1_str << " deleted as request.\n";
	  word1_str.clear();
	}
	else // don't wanna delete it, then output as it is
	{
	  fout << word1_str << letter; //out put word and the space to result file
	  word3_str = word2_str;
	  word2_str = word1_str;
	  word1_str.clear();
	}	
      } //if (word1_str == word2_str)
      else if ( !word1_str.empty() ) // not double-typing, not empty, move on
      {
	wd_num_line++;
	word3_str = word2_str;
	word2_str = word1_str;
	fout << word1_str << " ";
	word1_str.clear();	
      }  //else if ( !word1_str.empty() )
      else // more than one non-character detected, just output as it is
      {
	fout << letter;
      }
    } //if(letter == ' ')
    else if(letter == ',' || letter == '.') // middle or end of a sentence
    {    
      if (word1_str == word2_str) //same as the word before
      {
	wd_num_line++; //one more word counted
	cerr << "Double-typing spotted:\n" // report and ask if delete double-typing
	     << "\"" << word3_str << "\" \"" << word2_str << "\" \"" << word1_str << "\"" << endl
	     << "Do you reckon this is a double-typing and want to delete it?\n"
	     << "Choose yes or no:";
	cin >> yesno;
	while (yesno != "yes" && yesno != "y" && yesno != "Y" && yesno != "no" && yesno != "n" && yesno != "N")
	{
	  cerr << "Choose yes or no:";
	  cin >> yesno;
	}
	if (yesno == "yes" || yesno == "y" || yesno == "Y")
	{
	  dup_wd_num++; // one more double-typing
	  wd_num_line--; // one fewer word counted
	  flog << "Double-typing spotted in line " << line_num << ": \n"
	       << "\"" << word3_str << "\" \"" << word2_str << "\" \"" << word1_str << "\"" << endl
	       << word1_str << " deleted as request.\n";
	  word1_str.clear();
	  fout << '\b' << letter;
	}
	else // don't wanna delete it, then output as it is
	{
	  fout << word1_str << letter; //out put word and the space to result file
	  word3_str = word2_str;
	  word2_str = word1_str;
	  word1_str.clear();
	}	
      } //if (word1_str == word2_str)
      else if ( !word1_str.empty() ) // not double-typing, not empty, move on
      {
	wd_num_line++;
	word3_str = word2_str;
	word2_str = word1_str;
	fout << word1_str << " ";
	word1_str.clear();	
      }  //else if ( !word1_str.empty() )
      else // more than one non-character detected, just output as it is
      {
	fout << letter;
      }
    } //if(letter == ',')
    else if (letter == '\n' && letter0 == '\n') // found an empty line
    {
      fout << letter; //just add an empty line
      line_num++;
    }

    else if (letter == '\n') //end of a word at the end of a line
    {
      if (word1_str == word2_str) //same as the word before
      {
	wd_num_line++;
	cerr << "Double-typing spotted:\n"
	     << "\"" << word3_str << "\" \"" << word2_str << "\" \"" << word1_str << "\"" << endl
	     << "Do you reckon this is a double-typing and want to delete it?\n"
	     << "Choose yes or no:";
	cin >> yesno;
	while (yesno != "yes" && yesno != "y" && yesno != "Y" && yesno != "no" && yesno != "n" && yesno != "N")
	{
	  cerr << "Choose yes or no:";
	  cin >> yesno;
	}
	if (yesno == "yes" || yesno == "y" || yesno == "Y")
	{
	  dup_wd_num++;
	  wd_num_line--;
	  flog << "Double-typing spotted in line " << line_num << ": \n"
	       << "\"" << word3_str << "\" \"" << word2_str << "\" \"" << word1_str << "\"" << endl
	       << word1_str << " deleted as request.\n";
	  if (wd_num_line > 0)// there are words in this line left after deletion
          {
	    fout << letter;
	    wd_num_line = 0; //new line empty word in a line counter
	    line_num++;
	  }
	  else
	  {
	    line_num++;
	  }
	  word1_str.clear();
	}
	else // don't wanna delete it, then output as it is. empty word_num_line and add line_num by one
	{
	  fout << word1_str << letter;
	  word3_str = word2_str;
	  word2_str = word1_str;
	  word1_str.clear();
	  wd_num_line = 0;
	  line_num++;
	}
      } //if (word1_str == word2_str)
      else if ( !word1_str.empty() ) // not double-typing, not empty, move on
      {
	word3_str = word2_str;
	word2_str = word1_str;
	fout << word1_str << endl;
	word1_str.clear();
	wd_num_line = 0;
	line_num++;
      } //else if ( !word1_str.empty() )
      else 
      {
	fout << letter;
	wd_num_line = 0;
	line_num++;
      }
      
    }//else if(letter == '\n')
    else
    {
      word1_str += letter;
    }
    letter0 = letter;
  } //while (fin.get(letter))
  if (fin.eof())
  {
    if (word1_str == word2_str)
    {
      dup_wd_num++;
    }
    else 
    {
      fout << word1_str << '\n';
    }//if (word1_str == word2_str)
  }
  flog << "Number of double-typings spotted: " << dup_wd_num << endl;

  return 0;
}