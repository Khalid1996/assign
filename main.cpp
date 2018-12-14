#include "sequence.h"
#include "sequence.cpp">
#include "dna.h"
#include "dna.cpp"
#include "rna.h"
#include "rna.cpp"
#include "protein.h"
#include "protein.cpp"
#include "codonstable.h"
#include "codonstable.cpp"
#include <bits/stdc++.h>
using namespace std;

///         There's a problem while using Templates, should be solved
///         *****{{Mohamed Wa'el Abdelhady A'ref ------ 20170260 ------ G9}}*****

int main()
{
    int choice,choice1;
    DNA dna_obj;
    RNA rna_obj;
    Protein protein_obj;
    cout<<"******** Please enter a choice ********"<<endl;
    while (true)
    {

        cout<<"what's your input! "<<endl
                <<"1- DNA input "<<endl
                <<"2- RNA input "<<endl
                <<"3- Protein input "<<endl
                <<"4- Exit "<<endl
                <<"your choice: ";
        cin>>choice;
        if (choice==1)
        {
backtoDNA:

            cout<<"1-input DNA \n2-Read from file\n"
                <<"Enter choice:  ";
            cin>>choice1;

            if (choice1==1)
            {
                cout<<"Enter DNA strand: ";
                cin>>dna_obj;
            }
            else if (choice1==2)
            {
                dna_obj.Readfromfile();
            }
            else
            {

                cout<<"invalid input, please check"<<endl;
                goto backtoDNA;
            }


            cout<<"what function do you want to do? \n"<<
                "1-convert to RNA \n"<<
                "2-check validity and output will be bad chars \n"<<
                "3- build ComplementaryStrand \n"<<
                "4- print \n"<<
                "5-print to file \n"<<
                "6-check if your DNA = another DNA \n"<<
                "7-check if your DNA != another DNA \n"<<
                "8-your DNA + another DNA \n"<<
                "your choice : ";

            cin>>choice1;

            if (choice1==1)
            {
                rna_obj=dna_obj.ConvertToRNA();
                cout<<"the RNA strand = "<<rna_obj<<endl;
            }

            else if (choice1==2)
            {
                try
                {
                    dna_obj.checkvalidity();
                }
                catch (string x)
                {
                    cout<<x;
                }
            }
            else if (choice1==3)
            {
                dna_obj.BuildComplementaryStrand();
                cout<<"complementary strand: ";
                dna_obj.complementary_strand->Print();
            }
            else if (choice1 == 4)
            {
                cout<<"the DNA strand : "<<dna_obj<<endl;
            }
            else if (choice1==5)
            {
                dna_obj.Printtofile();
                cout<<"Done, file printed"<<endl;
            }
            else if (choice1==6)
            {
                DNA obj;
                cout<<"Enter the other DNA: ";
                cin>>obj;
                if (dna_obj==obj)
                    cout<<"your DNA = the other DNA "<<endl;
            }


            else if (choice1==7)
            {
                DNA obj;
                cout<<"Enter the other DNA: ";
                cin>>obj;
                if (dna_obj!=obj)
                    cout<<"your DNA != the other DNA "<<endl;
            }


            else if (choice1==8)
            {
                DNA obj;
                cout<<"Enter the other DNA: ";
                cin>>obj;

                DNA obj1(dna_obj+obj);
                cout<<"your DNA + another DNA = "<<obj1<<endl;
            }

        }

        else if (choice==2)
        {

backtoRNA:

            cout<<"1-input RNA \n"
                <<"2-Read from file \n"
                <<"Enter choice:  ";
            cin>>choice1;

            if (choice1==1)
            {
                cout<<"Enter DNA strand: ";
                cin>>rna_obj;
            }
            else if (choice1==2)
            {
                rna_obj.Readfromfile();
            }
            else
            {

                cout<<"invalid input, Please check"<<endl;
                goto backtoRNA;
            }


            cout<<"what function u wanna do ? \n"<<
                "1-convert to DNA \n"<<
                "2-convert to protein \n"<<
                "3- check validity and output will be bad chars  \n"<<
                "4- print \n"<<
                "5-print to file \n"<<
                "6-check if your RNA = another RNA \n"<<
                "7-check if your RNA != another RNA \n"<<
                "8-your RNA + another RNA \n"
                << "your choice : ";
            cin>>choice1;

            if (choice1==1)
            {
                dna_obj=rna_obj.ConvertToDNA();
                cout<<"the DNA strand = "<<dna_obj<<endl;
            }
            else if (choice1==2)
            {
                CodonsTable x;
                x.LoadCodonsFromFile("RNA_codon_table.txt");
                protein_obj=rna_obj.ConvertToProtein(x);
                cout<<"the protein strand : "<<protein_obj<<endl;

            }


            else if (choice1==3)
            {
                try
                {
                    rna_obj.checkvalidity();
                }
                catch (string x)
                {
                    cout<<x;
                }
            }
            else if (choice1 == 4)
            {
                cout<<"the RNA strand : "<<rna_obj<<endl;
            }
            else if (choice1==5)
            {
                rna_obj.Printtofile();
                cout<<"Done, file printed"<<endl;
            }
            else if (choice1==6)
            {
                RNA obj;
                cout<<"Enter the other RNA: ";
                cin>>obj;
                if (rna_obj==obj)
                    cout<<"your RNA = the other RNA "<<endl;
            }


            else if (choice1==7)
            {
                RNA obj;
                cout<<"Enter the other RNA: ";
                cin>>obj;
                if (rna_obj!=obj)
                    cout<<"your RNA != the other RNA "<<endl;
            }


            else if (choice1==8)
            {
                RNA obj;
                cout<<"Enter the other DNA: ";
                cin>>obj;

                RNA obj1(rna_obj+obj);
                cout<<"your RNA + another RNA = "<<obj1<<endl;
            }
        }
        else if (choice==3)
        {

backtoprotein:

            cout<<"1-input protein \n2-Read from file\n"
                <<"Enter choice:  ";
            cin>>choice1;

            if (choice1==1)
            {
                cout<<"Enter protein strand: ";
                cin>>protein_obj;
            }
            else if (choice1==2)
            {
                protein_obj.Readfromfile();
            }
            else
            {

                cout<<"invalid input, please check"<<endl;
                goto backtoprotein;
            }

            cout<<"what function u wanna do ? \n"<<
                "1- check validity and output will be bad chars  \n"<<
                "2 print \n"<<
                "3-print to file \n"<<
                "4-check if your protein = another protein \n"<<
                "5-check if your protein != another protein \n"<<
                "6-your protein + another protein \n"<<
                "7- GetDNAStrandsEncodingMe(DNA & bigDNA) \n"<<
                "your choice : ";
            cin>>choice1;


            if (choice1==1)
            {
                try
                {
                    protein_obj.checkvalidity();
                }
                catch (string x)
                {
                    cout<<x;
                }
            }
            else if (choice1 == 2)
            {
                cout<<"the protein strand : "<<protein_obj<<endl;
            }
            else if (choice1==3)
            {
                protein_obj.Printtofile();
                cout<<"Done, file printed"<<endl;
            }
            else if (choice1==4)
            {
                Protein obj;
                cout<<"Enter the other RNA: ";
                cin>>obj;
                if (protein_obj==obj)
                    cout<<"your protein = the other protein "<<endl;
            }


            else if (choice1==5)
            {
                Protein obj;
                cout<<"Enter the other RNA: ";
                cin>>obj;
                if (protein_obj!=obj)
                    cout<<"your protein != the other protein "<<endl;
            }


            else if (choice1==6)
            {
                Protein obj;
                cout<<"Enter the other DNA: ";
                cin>>obj;

                Protein obj1(protein_obj+obj);
                cout<<"your protein + another protein = "<<obj1<<endl;
            }

            else if (choice1==7)
            {

                DNA objj;
                cout<<"enter the bigdna : ";
                cin>>objj;
                protein_obj.GetDNAStrandsEncodingMe(objj);

            }
        }
        else
            system("Bye bye ;)");
            exit(0);
    }
    return 0;
}
