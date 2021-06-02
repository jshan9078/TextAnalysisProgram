#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector <double> MeanWordVec, SyllablesVec;
  double Quote=0, Sentences=0, SixCharWord=0, ThirdPerson=0, SecondPerson=0, WordCount=1, TotalSyllables=0, numc, numco, numcco, FirstPerson=0;
  //integer variable numc is the number of compound sentences
  //integer variable numco is the number of complex sentences
  //integer variable numcco is the number of compound-complex sentences
  cout << "Paste or type out something in this program to get stats." << endl;
  string TEXT;
  getline (cin, TEXT);
  int NumPunc=0;
  for (int c=0;c<TEXT.length();++c){ //c represents the current character being anaylsed 
    if (TEXT[c]=='.' || TEXT[c]==':' || TEXT[c]=='?' || TEXT[c]=='!' || TEXT[c]==','){
        NumPunc++;
    }
    if (TEXT[c]=='.' || TEXT[c]=='?' || TEXT[c]=='!' || TEXT[c]==';'){
        Sentences++;
    }
    if (TEXT[c]=='a' || TEXT[c]=='e' || TEXT[c]=='i' || TEXT[c]=='o' || TEXT[c]=='u'){
        TotalSyllables++;
    }
    if (TEXT[c] == ' ') {
      int CharCounter=0;
      WordCount++;
      double Syllables=0;
      for (int cc=c-1; ;--cc){
        if (TEXT[cc]!=' '){
            CharCounter++;
            if (TEXT[cc]=='a' || TEXT[cc]=='e' || TEXT[cc]=='i' || TEXT[cc]=='o' || TEXT[cc]=='u'){
                Syllables++;
            }
            if (TEXT[cc]=='A' || TEXT[cc]=='E' || TEXT[cc]=='I' || TEXT[cc]=='O' || TEXT[cc]=='U'){
                Syllables++;
            }
            if (TEXT[cc]=='y' || TEXT[cc]=='Y'){
                if (TEXT[cc-1] != 'a' || TEXT[cc-1]!='e' || TEXT[cc-1]!='i' || TEXT[cc-1]!='o' || TEXT[cc-1]!='u'){
                   if (cc!=TEXT.length()-1 && TEXT[cc+1]!=' '){
                       if (TEXT[cc+1] != 'A' || TEXT[cc+1]!='B' || TEXT[cc+1]!='C' || TEXT[cc+1]!='D' || TEXT[cc+1]!='E'){
                           Syllables++;
                       }
                   }
                }
            }
            if (cc==0){
                break;
            }
        }
        else {
            break;
        }
      }
      SyllablesVec.push_back(Syllables);
      MeanWordVec.push_back(CharCounter);
    }
    if (TEXT[c]=='.' && TEXT[c+1]== '.' && TEXT[c+2]=='.'){
      WordCount++;
      c=c+1;
      int charCounter=0;
      double SyllablesTwo=0;
      for (int ii=c-1; ;--ii){
        if (TEXT[ii]!=' '){
            charCounter++;
            if (TEXT[ii]=='a' || TEXT[ii]=='e' || TEXT[ii]=='i' || TEXT[ii]=='o' || TEXT[ii]=='u'){
                SyllablesTwo++;
            }
            else if (TEXT[ii]=='A' || TEXT[ii]=='E' || TEXT[ii]=='O' || TEXT[ii]=='I' || TEXT[ii]=='U'){
                SyllablesTwo++;
            }
            else if (TEXT[ii]=='y' || TEXT[ii]=='Y'){
                if (TEXT[ii-1] != 'a' || TEXT[ii-1]!='e' || TEXT[ii-1]!='i' || TEXT[ii-1]!='o' || TEXT[ii-1]!='u'){
                   if (ii!=TEXT.length()-1 && TEXT[ii+1]!=' '){
                       if (TEXT[ii+1] != 'A' || TEXT[ii+1]!='B' || TEXT[ii+1]!='C' || TEXT[ii+1]!='D' || TEXT[ii+1]!='E'){
                           SyllablesTwo++;
                       }
                   }
                }
            }
        }
        else {
            break;
        }
      }
      SyllablesVec.push_back(SyllablesTwo);
      MeanWordVec.push_back(charCounter);
    }
    if (TEXT[c]=='"'){
        Quote++;
    }
    if ((TEXT[c]==' ' && TEXT[c+1]=='m' && TEXT[c+2]=='e' && TEXT[c+3]==' ') || (TEXT[c]==' ' && TEXT[c+1]=='M' && TEXT[c+2]=='E' && TEXT[c+3]==' ') ){
        FirstPerson++;
    }
    if (TEXT[c]==' ' && TEXT[c+1]=='I' && TEXT[c+2]==' '){
        FirstPerson++;
    }
    if ((TEXT[c]==' ' && TEXT[c+1]=='w' && TEXT[c+2]=='e' && TEXT[c+3]==' ') || (TEXT[c]==' ' && TEXT[c+1]=='W' && TEXT[c+2]=='E' && TEXT[c+3]==' ') ){
        FirstPerson++;
    }
    if ((TEXT[c]==' ' && TEXT[c+1]=='u' && TEXT[c+2]=='s' && TEXT[c+3]==' ') || (TEXT[c]==' ' && TEXT[c+1]=='U' && TEXT[c+2]=='S' && TEXT[c+3]==' ') ){
        FirstPerson++;
    }
    if ((TEXT[c]==' ' && TEXT[c+1]=='y' && TEXT[c+2]=='o' && TEXT[c+3]=='u' && TEXT[c+4]==' ') || (TEXT[c]==' ' && TEXT[c+1]=='Y' && TEXT[c+2]=='O' && TEXT[c+3]=='U' && TEXT[c+4]==' ') ){
        SecondPerson++;
    }
    if ((TEXT[c]==' ' && TEXT[c+1]=='h' && TEXT[c+2]=='e' && TEXT[c+3]==' ') || (TEXT[c]==' ' && TEXT[c+1]=='H' && TEXT[c+2]=='E' && TEXT[c+3]==' ') ){
        ThirdPerson++;
    }
    if ((TEXT[c]==' ' && TEXT[c+1]=='i' && TEXT[c+2]=='t' && TEXT[c+3]==' ') || (TEXT[c]==' ' && TEXT[c+1]=='I' && TEXT[c+2]=='T' && TEXT[c+3]==' ') ){
        ThirdPerson++;
    }
    if ((TEXT[c]==' ' && TEXT[c+1]=='h' && TEXT[c+2]=='e' && TEXT[c+3]=='r' && TEXT[c+4]==' ') || (TEXT[c]==' ' && TEXT[c+1]=='H' && TEXT[c+2]=='E' && TEXT[c+3]=='R' && TEXT[c+4]==' ') ){
        ThirdPerson++;
    }
    if ((TEXT[c]==' ' && TEXT[c+1]=='s' && TEXT[c+2]=='h' && TEXT[c+3]=='e' && TEXT[c+4]==' ') || (TEXT[c]==' ' && TEXT[c+1]=='S' && TEXT[c+2]=='H' && TEXT[c+3]=='E' && TEXT[c+4]==' ') ){
        ThirdPerson++;
    }
    if ((TEXT[c]==' ' && TEXT[c+1]=='h' && TEXT[c+2]=='i' && TEXT[c+3]=='m' && TEXT[c+4]==' ') || (TEXT[c]==' ' && TEXT[c+1]=='H' && TEXT[c+2]=='I' && TEXT[c+3]=='M' && TEXT[c+4]==' ') ){
        ThirdPerson++;
    }
    if ((TEXT[c]==' ' && TEXT[c+1]=='t' && TEXT[c+2]=='h' && TEXT[c+3]=='e' && TEXT[c+4]=='y' && TEXT[c+5]==' ') || (TEXT[c]==' ' && TEXT[c+1]=='T' && TEXT[c+2]=='H' && TEXT[c+3]=='E' && TEXT[c+4]=='Y' && TEXT[c+5]==' ') ){
        ThirdPerson++;
    }
    if ((TEXT[c]==' ' && TEXT[c+1]=='t' && TEXT[c+2]=='h' && TEXT[c+3]=='e' && TEXT[c+4]=='m' && TEXT[c+5]==' ') || (TEXT[c]==' ' && TEXT[c+1]=='T' && TEXT[c+2]=='H' && TEXT[c+3]=='E' && TEXT[c+4]=='M' && TEXT[c+5]==' ') ){
        ThirdPerson++;
    }
  }
  double TotalChars=0;
  int LongWords=0;
  int ShortWords=0;
  int DifficultWords=0;
  for (int e=0;e<MeanWordVec.size();++e){ //e represents the current element in the vector(array) being analysed
    TotalChars=TotalChars+MeanWordVec[e];
    if (MeanWordVec[e]==6){
        SixCharWord++;
    }
    else if (MeanWordVec[e]>8){
        DifficultWords++;
    }
    else if (MeanWordVec[e]>6){
        LongWords++;
    }
    if (MeanWordVec[e]<5){
        ShortWords++;
    }
  }
  double Monosyllabic=0, Polysyllabic=0;
  for (int ee=0;ee<SyllablesVec.size();++ee){
      if (SyllablesVec[ee]==1){
        Monosyllabic++;
      }
      if (SyllablesVec[ee]>=3){
        Polysyllabic++;
      }
  }
  double AverageWord=(TotalChars-NumPunc)/MeanWordVec.size();
  int TotalQuotations=Quote/2;
  double MeanSentenceLength=WordCount/Sentences;
  double MeanSyllables=TotalSyllables/WordCount;
  int TotalPerspective = FirstPerson+ SecondPerson+ThirdPerson;
  cout << "Your text has been successfully processed. Collected data is shown below. Thank you for using Jonathan's text analysis algorithms." << endl;
  cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
  cout << endl;
  cout << "                       -->Base Observations<--         " << endl;
  cout << "__________________________________________________________________________" << endl;
  cout << "Word Count: " << WordCount << endl;
  cout << "Number of Grammatically Correct Sentences: " << Sentences << endl;
  cout << "Total Non-Whitespace Characters: " << TotalChars << endl;
  cout << endl;
  cout << "                 -->Basic Anaylysis of Words Words<--" << endl;
  cout << "__________________________________________________________________________" << endl;
  cout << "Average (Mean) Number of Characters Per Word: " << AverageWord << endl;
  cout << "Average (Mean) Number of Words Per Sentence: " << MeanSentenceLength << endl;
  cout << "Number of 6 Letter Words: " << SixCharWord << endl;
  cout << "Number of Very Easy Words (<6 characters): " << ShortWords << endl;
  cout << "Number of Easy Words (>6 characters): " << LongWords << endl;
  cout << "Number of Difficult Words (>8 characters): " << DifficultWords << endl;
  cout << endl;
  cout << "            -->In-Depth Analysis of Syllable Distribution<--" << endl;
  cout << "__________________________________________________________________________" << endl;
  cout << "Average (mean) Number of Syllables Per Word: " << MeanSyllables << endl;
  cout << "Number of Monosyllabic Words (Words with One Syllable): " << Monosyllabic << endl;
  cout << "Number of Polysyllabic Words (Words with Three or More Syllable): " << Polysyllabic << endl;
  cout << "Percentage of Monosyllabic Words in the Text: " << Monosyllabic/WordCount*100 << '%' << endl;
  cout << "Percentage of Polysyllabic Words in the Text: " << Polysyllabic/WordCount*100 << '%' << endl;
  cout << endl;
  cout << "-->Observations Used to Deduct the Perspective (1st, 2nd or 3rd person)<--" << endl;
  cout << "__________________________________________________________________________" << endl;
  cout << "Number of Quotations: " << TotalQuotations << endl;
  cout << "Number of First Person Indicators: " << FirstPerson << endl;
  cout << "Number of Second Person Indicators: " << SecondPerson << endl;
  cout << "Number of Third Person Indicators: " << ThirdPerson << endl;
  cout << endl;
  cout << "  -->Probabilities of A Certain Perspective Being Used by the Author<--" << endl;
  cout << "__________________________________________________________________________" << endl;
  cout << "Probability of the Text Being Written in the First Person Perspective: " << FirstPerson/TotalPerspective*100 << '%' << endl;
  cout << "Probability of the Text Being Written in the Second Person Perspective: " << SecondPerson/TotalPerspective*100 << '%' <<  endl;
  cout << "Probability of the Text Being Written in the Third Person Perspective: " << ThirdPerson/TotalPerspective*100 << '%' << endl;
  cout << endl;
  cout << "Most likely perspective used by the author determined by the Perspective Finding Algorithm: " << endl;
  cout << "-------------------------------------------------------------------------------------------" << endl;
  if (FirstPerson>ThirdPerson && FirstPerson>SecondPerson){
      cout << "First Person" << endl;
      cout << "Probability: " << FirstPerson/TotalPerspective*100 << '%' << endl;
  }
  else if (SecondPerson>ThirdPerson && FirstPerson<SecondPerson){
      cout << "Second Person" << endl;
      cout << "Probability: " << SecondPerson/TotalPerspective*100 << '%' << endl;
  }
  else if (SecondPerson<ThirdPerson && FirstPerson<ThirdPerson){
      cout << "Third Person" << endl;
      cout << "Probability: " << ThirdPerson/TotalPerspective*100 << '%' << endl;
  }
  else if (FirstPerson==ThirdPerson){
      cout << "There is an equal probability of the text being in the 1st Person and 3rd Person." << endl;
      cout << "Probability: " << ThirdPerson/TotalPerspective*100 << '%' << endl;
  }
  else if (SecondPerson==ThirdPerson){
      cout << "There is an equal probability of the text being in the 2nd Person and 3rd Person." << endl;
      cout << "Probability: " << ThirdPerson/TotalPerspective*100 << '%' << endl;
  }
  else if (SecondPerson==FirstPerson){
      cout << "There is an equal probability of the text being in the 1st Person and 2nd Person." << endl;
      cout << "Probability: " << FirstPerson/TotalPerspective*100 << '%' << endl;
  }
  return 0;
}