// Delay and Reverb calulator 


#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

void timeDivisions (float bpm);

void reverbCalculator (float bpm);

void displayReverb (float predelay, float decay, float totaltime, int columnWidth);

void menu ();

int menuselect = 1;


int main()
{
    float bpm; 
    
    
    do {
      
        switch(menuselect) {
    
        case 1 : 
             cout<<endl<<"Insert BPM : ";
             cin>>bpm;
             timeDivisions(bpm);
        break;
    
        case 2 : 
             reverbCalculator(bpm);
        break;
    
        default : return 0; }
    
    
    } while (menuselect==1 || menuselect==2);
    
    
    return 0;
}


void timeDivisions (float bpm) {
    
    float ms = 60000 / bpm;
    int columnWidth = 10; 

    
    cout << fixed << setprecision(2); 
    cout << left; 

    cout << endl;
    
    cout << " -----------------------------------------------------------" << endl;
    
    cout << "| " << setw(columnWidth) << "Note"   << "| " << setw(columnWidth) << "Length" << "    | " << setw(columnWidth) << "Dotted"     << "    | "  << setw(columnWidth) << " Triplets"     << "    |" <<endl;
    cout << "| " << setw(columnWidth) << "    "   << "| " << setw(columnWidth) << "      " << "    | " << setw(columnWidth) << "      "     << "    | "  << setw(columnWidth) << "      "        << "    |" << endl;
    
    cout << "| " << setw(columnWidth) << "1/1"    << "| " << setw(columnWidth) << ms * 4   << " ms | " << setw(columnWidth) << ms * 6       << " ms | "  << setw(columnWidth) << ((ms*4)*2)/ 3   << " ms |" << endl;       
    cout << "| " << setw(columnWidth) << "1/2"    << "| " << setw(columnWidth) << ms * 2   << " ms | " << setw(columnWidth) << ms * 3       << " ms | "  << setw(columnWidth) << ((ms*2)*2)/ 3   << " ms |" << endl;
    cout << "| " << setw(columnWidth) << "1/4"    << "| " << setw(columnWidth) << ms * 1   << " ms | " << setw(columnWidth) << ms * 1.5     << " ms | "  << setw(columnWidth) << ((ms*1)*2)/ 3   << " ms |" << endl;
    cout << "| " << setw(columnWidth) << "1/8"    << "| " << setw(columnWidth) << ms / 2   << " ms | " << setw(columnWidth) << ms / 4 * 3   << " ms | "  << setw(columnWidth) << ((ms/2)*2)/ 3   << " ms |" << endl;
    cout << "| " << setw(columnWidth) << "1/16"   << "| " << setw(columnWidth) << ms / 4   << " ms | " << setw(columnWidth) << ms / 8 * 3   << " ms | "  << setw(columnWidth) << ((ms/4)*2)/ 3   << " ms |" << endl;
    cout << "| " << setw(columnWidth) << "1/32"   << "| " << setw(columnWidth) << ms / 8   << " ms | " << setw(columnWidth) << ms / 16 * 3  << " ms | "  << setw(columnWidth) << ((ms/8)*2)/ 3   << " ms |" << endl;
    cout << "| " << setw(columnWidth) << "1/64"   << "| " << setw(columnWidth) << ms / 16  << " ms | " << setw(columnWidth) << ms / 32 * 3  << " ms | "  << setw(columnWidth) << ((ms/16)*2)/ 3  << " ms |" << endl;
    cout << "| " << setw(columnWidth) << "1/128"  << "| " << setw(columnWidth) << ms / 32  << " ms | " << setw(columnWidth) << ms / 64 * 3  << " ms | "  << setw(columnWidth) << ((ms/32)*2)/ 3  << " ms |" << endl;
    cout << "| " << setw(columnWidth) << "1/256"  << "| " << setw(columnWidth) << ms / 64  << " ms | " << setw(columnWidth) << ms / 128 * 3 << " ms | "  << setw(columnWidth) << ((ms/64)*2)/ 3  << " ms |" << endl;
    cout << "| " << setw(columnWidth) << "1/512"  << "| " << setw(columnWidth) << ms / 128 << " ms | " << setw(columnWidth) << ms / 256 * 3 << " ms | "  << setw(columnWidth) << ((ms/128)*2)/ 3 << " ms |" << endl;
    cout << "| " << setw(columnWidth) << "1/1024" << "| " << setw(columnWidth) << ms / 256 << " ms | " << setw(columnWidth) << ms / 512 * 3 << " ms | "  << setw(columnWidth) << ((ms/256)*2)/ 3 << " ms |" << endl;
    
    cout << "| " << setw(columnWidth) << "    "   << "| " << setw(columnWidth) << "      " << "    | " << setw(columnWidth) << "      "     << "    | "  << setw(columnWidth) << "      "        << "    |" << endl;    
    cout << " -----------------------------------------------------------" << endl;
    
    menu();
    
    
}
    


void displayReverb (float predelay, float decay, float totaltime, int columnWidth) { 
    
    cout <<endl<<endl;
    cout << " --------------------------------------------------------" << endl;
    cout << "| "<<setw(columnWidth)<<"Pre-delay (ms) " <<" | "<< setw(columnWidth)<<"Decay time (ms) " <<" | "<<setw(columnWidth)<<"Total time (ms) " << " | "<<endl;
    cout << "| "<<setw(columnWidth)<<"          "      <<" | "<< setw(columnWidth)<<"           "      <<" | "<<setw(columnWidth)<<"           "      << " | "<<endl;
    cout << "| "<<setw(columnWidth)<<predelay          <<" | "<< setw(columnWidth)<<decay              <<" | "<<setw(columnWidth)<<totaltime          << " | "<<endl;
    cout << "| "<<setw(columnWidth)<<"          "      <<" | "<< setw(columnWidth)<<"           "      <<" | "<<setw(columnWidth)<<"           "      << " | "<<endl;
    cout << " --------------------------------------------------------" << endl;
}    




void reverbCalculator (float bpm) {
    
    float ms = 60000 / bpm;
    float predelay, totaltime, decay;
    int sel;
    int columnWidth = 16; 
    
    cout<<"\nREVERB CALCULATOR : "<<endl<<endl;
    cout<<"Presets - [1]" <<
    endl<<"Custom  - [2]\t"; 
    cin>>sel;
    
    if (sel==1) {
        
        cout<<"\nPRESETS : "<<endl<<endl;
        cout<<"Hall       - [1]"<<
        endl<<"Large Room - [2]"<<
        endl<<"Small Room - [3]"<<
        endl<<"Tight      - [4]\t";
        cin>>sel;
        cout<<endl<<endl;
        
        switch(sel) {
            
            case 1 : predelay  = ms/8;                 //  1/32
                     totaltime = ms*8;                 //  2/1 
                     decay = totaltime - predelay;
                     
                     cout<<"       HALL (Pre-Delay : 1/32 | Reverb Time : 2/1)";
                     displayReverb (predelay, decay, totaltime, columnWidth);
                     break;
            
            case 2 : predelay  = ms/16;                //  1/64
                     totaltime = ms*4;                 //  1/1 
                     decay = totaltime - predelay;
                     
                     cout<<"    LARGE ROOM  (Pre-Delay : 1/64 | Reverb Time : 1/1)";
                     displayReverb (predelay, decay, totaltime, columnWidth);
                     break;
            
            case 3 : predelay  = ms/32;                //  1/128
                     totaltime = ms*2;                 //  1/2 
                     decay = totaltime - predelay;
                     
                     cout<<"    SMALL ROOM (Pre-Delay : 1/128 | Reverb Time : 1/2)";
                     displayReverb (predelay, decay, totaltime, columnWidth);
                     break;
                     
            case 4 : predelay  = ms/64;                //  1/256
                     totaltime = ms*1;                 //  1/4 
                     decay = totaltime - predelay;
                     
                     cout<<"      TIGHT (Pre-Delay : 1/256 | Reverb Time : 1/4)";
                     displayReverb (predelay, decay, totaltime, columnWidth);
                     break;
                     
            default : cout<<"ERROR : Invalid Option"<<endl;
        }
    
        
    } else if (sel==2) {
        
        cout<<"\n\nCUSTOM REVERB : "<<endl<<endl;
        cout<<"Total Reverb Length (ms) : ";
        cin>>totaltime;
        cout<<endl<<"Pre-delay (ms) : ";
        cin>>predelay;
        decay= totaltime-predelay;
       
        displayReverb (predelay, decay, totaltime, columnWidth);
        
    } else { cout<<"ERROR : Invalid Option"<<endl; }
    
    menu();
}



void menu () { 
        
        int& a = menuselect;
        
        cout<<endl<<endl;
        cout<<"Change BPM - [1]    Reverb Calculator - [2]    Exit - [3]   ";
        cin>>a;
        cout<<endl;
        
        if (a!=1 && a!=2 && a!=3) {cout<<"ERROR : Invalid Option";}
        
}
        
        

