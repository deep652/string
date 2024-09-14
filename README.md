Important string functions
stringstream

std::getline()
parameters are 
std::getline(std::istream& inputStream, std::string& str);
std::getline(std::istream& inputStream, std::string& str, char delimiter);

first parameter is source from where we want to extract the string/data
second parameter is the targer where we want to store the data
third parameter is the delimiter at which we want to stop reading the data

so to get the data while we type from keyboard and store it into string we can use the above 1st way. here the default delimiter is '\n'. so it will ready all the keystroke until a \n is pressed

second, we can mention a custom delimiter where it will stop reading the data

the above we can utilise to break a stringstream to get strings of words based on custom delimiter

ss -> string stream variable having "deep,shikha"
getline(ss,word,',') -> will give me deep

for default '' space as a delimiter we can utilise stringstram >> << operators to put data into ss or fetch data from ss

for eg. 
stringstream ss = "deep shikha"

ss<<1234 ->note we are writing integer into stringstream directly and it is allowed

cout<<ss.str(); -> deep shikha1234

ss>>word -> this will give me deep . this doesn't modify the ss and it remains intact. the internal pointers are moved, so if we use it while loop, once all words of the ss is finished, eof is returned making it come out of the loop
