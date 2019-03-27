#include <iostream>


#include <string>


#include <iostream>


#include <iomanip>


#include <fstream>



using namespace std;



struct places{

    

    

    

    

    

    int code;

    

    string state;

    

    string cname;

    

    int population;

    

    double area;

    

    double latitude;

    

    double longitude;

    

    int roadint;

    

    double distance;

    

    places * nextsamehash;

    

    

};


const int tablesize = 26000;

places * table[tablesize];



int Hash(string s){

    int value = 79561;

    for(int i = 0; i <s.length(); i+=1)

        value = value * 69 + s[i];

    if(value < 0)

        value = -value;

    return value % tablesize;

    

}





places * search(string word, places * list)

{ while (list != NULL)

{ if (word == list->cname){

    cout << list->state << " " <<endl;

    return list;}


    list = list->nextsamehash; }

    return NULL; }


places * search2(string word, string words, places * list){

    while(list!=NULL){

        if( words==list->state && word == list->cname){

            cout << " CODE: " << list->code << endl;

            

            cout << "STATE: " << list->state << endl;

            

            cout << "NAME: " << list ->cname << endl;

            

            cout << "Population: " << list->population << endl;

            

            cout << "Area: " << list->area << endl;

            

            cout << "Latitude: " << list->latitude << endl;

            

            cout << "Longitude: " << list->longitude << endl;

            

            cout << "Road Code: " << list->roadint << endl;

            

            cout << "Distance: " << list->distance << endl;

        list= list->nextsamehash;

            break;

        }

    

    }

    return NULL;

}





int main() {

    int k = 10, pos;

    

  

    

    places * ptr;

    places * it;

  

    ifstream file ("/home/www/class/een318/named-places.txt");

    

    string line, input,input2;

    

    for(int i =0; i < tablesize; i++)

        table[i]=NULL;

    

    


    

    

    //CITY NAME

    

    //it->cname = a;

    

    

   

    for(string line; getline(file, line ); )

    {

      

        it = new places();

        

        int k = 10,j=0;

        

        string a,b,c,d,e,f,g,h;

        

        

        

        

        

        string x = line.substr(0,8);

        

        // CITY CODE

        

        int y = atoi(x.c_str());

        

        it->code = y;

        

        // STATE ABREV

        

        string z = line.substr(8,2);

        

         it->state = z;

        

        

        

        for(k;k<line.length();k++){

            

            if(line[k] != ' '){

                

                a = a+line[k];

                

            }

            

            else if(line[k] == ' ' && line[k+1] != ' '){

                

                a = a+line[k];

                

            }

            

            else

                

                break;

            

        }

        

        

        

        //CITY NAME

        

        it->cname = a;

        

       

        

        line.erase(0,k);

        

        

        

        

        

        int i = line.length()-1;

        

        

        

        for(i; i >= 0;i--){

            

            if(line[i]== ' ' && line[i-1]==' '){

                

                line.erase(i,1);

                

            }

            

        }

        

        line.erase(0,1);

        

        

        

        while(true){

            

            if(line[j] != ' '){

                

                b = b+line[j];

                

                j++;

                

            }

            

            

            

            else

                

                break;

            

        }

        

        

        

        

        

        

        

        //POPULATION

        

        int p = atoi(b.c_str());

        

        it->population=p;

        

        line.erase(0,j+1);

        

        

        

        j=0;

        

        while(true){

            

            if(line[j] != ' '){

                

                c = c+line[j];

                

                j++;

                

            }

            

            

            

            else

                

                break;

            

        }

        

        //AREA

        

        

        

        float s = atof(c.c_str());

        

         it->area=s;

        

        

        

        line.erase(0,j+1);

        

        

        

        j=0;

        

        while(true){

            

            if(line[j] != ' '&& line[j] != '-'){

                

                d = d+line[j];

                

                j++;

                

            }

            

            else

                

                break;

            

        }

        

        

        

        //LATITUDE

        

        float u = atof(d.c_str());

        

        it->latitude = u;

        

        line.erase(0,j);

        

        

        

        

        

        j=0;

        

        while(true){

            

            if(line[j] != ' '){

                

                e = e+line[j];

                

                j++;

                

            }

            

            

            

            else

                

                break;

            

        }

        

        

        

        //LONGITUDE

        

        float t = atof(e.c_str());

        

        it->longitude = t;

        

        

        

        line.erase(0,j+1);

        

        

        

        j=0;

        

        while(true){

            

            if(line[j] != ' '){

                

                f = f+line[j];

                

                j++;

                

            }

            

            

            

            else

                

                break;

            

        }

        

        //ROAD

        

        

        

        

        

        int w = atoi(f.c_str());

        

        it->roadint = w;

        

        line.erase(0,j+1);

        

        

        

        j=0;

        

        while(true){

            

            if(line[j] != ' '){

                

                g = g+line[j];

                

                j++;

                

            }

            

            

            

            else

                

                break;

            

        }

        

        float r = atof(g.c_str());

        

        it->distance = r;

        

        line.erase(0,j);

        

        

        int pos = Hash(it->cname);

        

        table[pos] = new places();

        

        table[pos]->code = it->code;

        

        table[pos]->state = it->state;

        

        table[pos]->cname = it->cname;

        

        table[pos]->population=it->population;

        

        table[pos]->area=it->area;

        

        table[pos]->latitude = it->latitude;

        

        table[pos]->longitude = it->longitude;

        

        table[pos]->roadint = it->roadint;

        

        table[pos]->distance = it->distance;

        

        table[pos]->nextsamehash = table[pos];

        it=NULL;

    

    

        

    }

   

    while(true)

    {

    

        cout << "City name: ";

        getline(cin,input);

        pos = Hash(input);

        

        ptr=table[pos];

        

     

        cout << "States that have " << input << " city: ";

        search(input,table[pos]);

        cout << "\nChoose a state: ";

        getline(cin,input2);

        search2(input,input2,table[pos]);

            

        

                }

                    

                

            }