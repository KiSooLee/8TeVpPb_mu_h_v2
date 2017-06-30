//Headers{{{
#include <TROOT.h>
#include <TTree.h>
#include <TString.h>
#include <TClonesArray.h>
//}}}

//Basic info{{{
//Double_t rapBinsArr[] = {0, 1.2, 2.4};
Double_t rapBinsArr[] = {0, 2.4};
//Double_t ptBinsArr[] = {0, 6, 30};
Double_t ptBinsArr[] = {0, 30};
//Double_t multBinsArr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 95, 100, 105, 110, 120, 130, 140, 150, 160, 300};
//Double_t multBinsArr[] = {0, 10, 20, 30, 100, 300};
Double_t multBinsArr[] = {0, 300};

const Int_t rap_narr = sizeof(rapBinsArr)/sizeof(double);
const Int_t pt_narr = sizeof(ptBinsArr)/sizeof(double);
const Int_t mult_narr = sizeof(multBinsArr)/sizeof(double);
//}}}

class SglMuon
{
//{{{
	public:

	UInt_t eventNb, LS;
	Double_t zVtx, dphi, deta;
	Double_t mass, y, pt, phi;
	Double_t mu_eta, mu_pt, mu_phi;
	Double_t trk_eta, trk_pt, trk_phi;
	Double_t weight;
	Double_t mult;
	Int_t Ntrg, Nass;
	TClonesArray* Vec_trg;
	TClonesArray* Vec_ass;

	void clear()
	{
		eventNb = -99; LS = -99; zVtx = -99; dphi = -99, deta = -99;
		mass = -99; y = -99; pt = -99; phi = -99;
		mu_eta = -99; mu_pt = -99; mu_phi = -99;
		trk_eta = -99; trk_pt = -99; trk_phi = -99;
		weight = -99; mult = -99;
		Ntrg = -99; Nass = -99;
		Vec_trg->Clear();
		Vec_ass->Clear();
	}

	void BuildBranch(TTree* tout)
	{
		tout->Branch("eventNb", &eventNb);
		tout->Branch("LS", &LS);
		tout->Branch("zVtx", &zVtx);
		tout->Branch("dphi", &dphi);
		tout->Branch("deta", &deta);
		tout->Branch("mass", &mass);
		tout->Branch("y", &y);
		tout->Branch("pt", &pt);
		tout->Branch("phi", &phi);
		tout->Branch("mu_eta", &mu_eta);
		tout->Branch("mu_pt", &mu_pt);
		tout->Branch("mu_phi", &mu_phi);
		tout->Branch("trk_eta", &trk_eta);
		tout->Branch("trk_pt", &trk_pt);
		tout->Branch("trk_phi", &trk_phi);
		tout->Branch("weight", &weight);
		tout->Branch("mult", &mult);
		tout->Branch("Ntrg", &Ntrg);
		tout->Branch("Nass", &Nass);
		Vec_trg= new TClonesArray("TLorentzVector", 1000);
		Vec_ass = new TClonesArray("TLorentzVector", 1500);
		tout->Branch("Vec_trg", "TClonesArray", &Vec_trg, 32000, 0);
		tout->Branch("Vec_ass", "TClonesArray", &Vec_ass, 32000, 0);
	}
//}}}
};
