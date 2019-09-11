// Aaron Shabanian
// Id:2314391
#include <fstream>
#include <cmath>
#include <iostream>
#include <math.h>
using namespace std;
int main(){
  bool cont=true;
  // Creates file to write to
  ofstream myfile ("yourname.out");
  // While loop to decide when to creating lists until user says to stop
  while(cont=true){
  string filename;
  cout<<"Please enter the name of the file: ";
  cin>>filename;
  //Initialization of all variables
  string line;
  ifstream readfile (filename);
  int len=0;
  int sum=0;
  int counter=0;
  double variance=0;
  double diffSquared=0;
  double average =0;
  int aCount=0;
  int cCount=0;
  int tCount=0;
  int gCount=0;
  double a=0;
  double b=0;
  double c=0;
  double d=0;
  double num=0;
  cont=false;
  string lines;
  string answer;
  // Checks if user inputted file exists
  if (readfile.is_open()){
    while(getline(readfile, line)){
      len=line.length();
      sum+=len;
      counter++;
      // Counts amount of each char to help determine relative probability
      for(int i=0;i<len;i++){
        char letter= tolower(line[i]);
        if(letter==('a')){
        aCount++;
        }
        if(letter=='c'){
          cCount++;
        }
        if((letter=='t')){
          tCount++;
        }
        if(letter=='g'){
          gCount++;
        }

    }
  }
}
  else cout << "File does not exist";
  //calculates average
    average=((double)sum/(double)counter);
    readfile.close();
    // I close the file and then re read it to know try to calculate what is neccessary for variance and standard deviation
    ifstream readfile2 (filename);
  if(readfile2.is_open()){
    while(getline(readfile2, line)){
      len=line.length();
      diffSquared+= ((len-average)*(len-average));
      //diffSquared is neccessary for variance
    }
  }

  readfile2.close();
  //closes the file the second time
    variance=(diffSquared/(double)counter);
    double aRelative=0;
    double cRelative=0;
    double tRelative=0;
    double gRelative=0;
    // finds relatve probability by dividing number of letter letter by the total sum
    aRelative= (double)aCount/(double)sum;
    cRelative= (double)cCount/(double)sum;
    tRelative= (double)tCount/(double)sum;
    gRelative= (double)gCount/(double)sum;
    // finds relatve probability by dividing number of letter letter by multiplying probability of once letter
    // by another letter
    double aaRelative=aRelative*aRelative;
    double acRelative=aRelative*cRelative;
    double atRelative=aRelative*tRelative;
    double agRelative=aRelative*gRelative;
    double caRelative=cRelative*aRelative;
    double ccRelative=cRelative*cRelative;
    double ctRelative=cRelative*tRelative;
    double cgRelative=cRelative*gRelative;
    double taRelative=tRelative*aRelative;
    double tcRelative=tRelative*cRelative;
    double ttRelative=tRelative*tRelative;
    double tgRelative=tRelative*gRelative;
    double gaRelative=gRelative*aRelative;
    double gcRelative=gRelative*cRelative;
    double gtRelative=gRelative*tRelative;
    double ggRelative=gRelative*gRelative;
    // begins writing to the file
  if (myfile.is_open())
  {
    myfile <<" Aaron Shabanian \n";
    myfile <<" Student Id: 2314391 \n";
    myfile << "The sum is: ";
    myfile << sum;
    myfile<<" \n";
    myfile << "The average is: ";
    myfile << average;
    myfile<<" \n";
    myfile << "The variance is: ";
    myfile << variance;
    myfile<<" \n";
    myfile<<  "The standard deviation is: ";
    myfile << sqrt(variance);
    myfile<<" \n";
    myfile<< "The Relative probability of A is: ";
    myfile<<aRelative;
    myfile<<"\n";
    myfile<< "The Relative probability of C is: ";
    myfile<<cRelative;
    myfile<<"\n";
    myfile<< "The Relative probability of T is: ";
    myfile<<tRelative;
    myfile<<"\n";
    myfile<< "The Relative probability of G is: ";
    myfile<<gRelative;
    myfile<<"\n";
    myfile<<"Nuclear Bigram probability: ";
    myfile<<"\n";
    myfile<<"AA: ";
    myfile<<aaRelative;
    myfile<<"\n";
    myfile<<"AC: ";
    myfile<<acRelative;
    myfile<<"\n";
    myfile<<"AT: ";
    myfile<<atRelative;
    myfile<<"\n";
    myfile<<"AG: ";
    myfile<<agRelative;
    myfile<<"\n";
    myfile<<"CA: ";
    myfile<<caRelative;
    myfile<<"\n";
    myfile<<"CC: ";
    myfile<<ccRelative;
    myfile<<"\n";
    myfile<<"CT: ";
    myfile<<ctRelative;
    myfile<<"\n";
    myfile<<"CG: ";
    myfile<<cgRelative;
    myfile<<"\n";
    myfile<<"TA: ";
    myfile<<taRelative;
    myfile<<"\n";
    myfile<<"TC: ";
    myfile<<tcRelative;
    myfile<<"\n";
    myfile<<"TT: ";
    myfile<<ttRelative;
    myfile<<"\n";
    myfile<<"TG: ";
    myfile<<tgRelative;
    myfile<<"\n";
    myfile<<"GA: ";
    myfile<<gaRelative;
    myfile<<"\n";
    myfile<<"GC: ";
    myfile<<gcRelative;
    myfile<<"\n";
    myfile<<"GT: ";
    myfile<<gtRelative;
    myfile<<"\n";
    myfile<<"GG: ";
    myfile<<ggRelative;
    myfile<<"\n";
    // The following 4 lines are used to determine which letter the system should print so they are all on a scale from 0-1
    double aPlusRelative=aRelative;
    double cPlusRelative=cRelative+aPlusRelative;
    double tPlusRelative=cPlusRelative+tRelative;
    double gPlusRelative=tPlusRelative+gRelative;
    // Prints 1000 lines of DNA Strings
    for(int i=0;i<1000;i++){
      //using gausian distribution to determine how long each dna string should be
      a = ((double) rand() / (RAND_MAX));
      b= ((double) rand() / (RAND_MAX));
      c=sqrt((-2)*log(a))*cos(2*M_PI*b);
      d=(((sqrt(variance))*c)+average);
      d=round(d);
      int lowest=a;
      int second=5000;
      //This is where the letter determiner is executed as it finds a rand decimal between 0 and 1 and prints the letter
      // corresponding to the decimal range calculated above
      for(int j=0; j<d;j++){
          num=((double) rand() / (RAND_MAX));
          if(num<=aPlusRelative){
            myfile<<"A";
          }
          else if(num<=cPlusRelative){
            myfile<<"C";
          }
          else if(num<=tPlusRelative){
            myfile<<"T";
          }
          else{
            myfile<<"G";
          }
      }
      myfile<<"\n";
    }
    //User decides whether to generate anpther list or not
    cout<<"Would you like to generate another list?";
    cin>>answer;
    if (answer==("yes")){
      cont=true;
      myfile<<"_____________________________________________________________________ \n";
      myfile<<"Next List";
    }
    else{
      // ends program by closing writer file
      break;
      cont=false;
      myfile.close();
    }
  }
  else cout << "Unable to open file";
}
  return 0;
}
