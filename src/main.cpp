#include <iostream>
#include "TROOT.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TBrowser.h"
#include "TFrame.h"
#include "TApplication.h"
#include "TImage.h"

using namespace std;

int main(int argc, char *argv[])
{
	TApplication *myApp = new TApplication("myApp", &argc, argv);
	TCanvas *c1 = new TCanvas("c1", "c1", 200, 10, 1280, 720);
	TH1D h1("h1","Histo from a Vector",10,0,10);
	std::vector<double> testData;
	testData.push_back(1.0);
	testData.push_back(1.5);
	testData.push_back(6.0);
	testData.push_back(6.5);
	testData.push_back(5.0);
	testData.push_back(2.5);
	testData.push_back(8.0);
	testData.push_back(8.0);
	testData.push_back(8.0);
	double* p = testData.data();

	for (const auto& data: testData)
	{
		h1.Fill(*(&data));
	}
	
	h1.Draw();

	c1->Update();
	c1->GetFrame()->SetBorderSize(12);
	c1->Modified();

	c1->Print("./result.png");

	myApp->Run();
	return 0;
}