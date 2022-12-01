void CombineSF(int which){
//TFile InFileEta("Eta_6_NoXsecW__Everything_SF.root","READ");
//TFile InFileET("ET_6_NoXsecW__Everything_SF.root","READ");
//string name="ET_Eta_6_NoXsecW__Everything_SF.root";
if (which==1) {
TFile InFileEta("Eta_6_medium_40GeV__Everything_SF.root","READ");
TFile InFileET("ET_6_medium_noCrack__Everything_SF.root","READ");
string name="ET_Eta_6_noCrack_40GeV_medium__Everything_SF.root";
}
else if (which==2) {
TFile InFileEta("Eta_6_40GeV_blayer__Everything_SF.root","READ");
TFile InFileET("ET_6_noCrack_blayer__Everything_SF.root","READ");
string name="ET_Eta_6_noCrack_40GeV_blayer__Everything_SF.root";
}
TFile OutFile(name.c_str(),"RECREATE");

TH1F * h_SFstat_ET_mcatnlo=(TH1F*) InFileET.Get("h_SFstat_ET_mcatnlo");
TH1F * h_SFstat_ET_pythia=(TH1F*) InFileET.Get("h_SFstat_ET_pythia");
TH1F * h_SFstat_eta_mcatnlo=(TH1F*) InFileEta.Get("h_SFstat_eta_mcatnlo");
TH1F * h_SFstat_eta_pythia=(TH1F*) InFileEta.Get("h_SFstat_eta_pythia");
TH1F * h_SF_ET_mcatnlo=(TH1F*) InFileET.Get("h_SF_ET_mcatnlo");
TH1F * h_SF_ET_pythia=(TH1F*) InFileET.Get("h_SF_ET_pythia");
TH1F * h_SF_eta_mcatnlo=(TH1F*) InFileEta.Get("h_SF_eta_mcatnlo");
TH1F * h_SF_eta_pythia=(TH1F*) InFileEta.Get("h_SF_eta_pythia");
TH1F * h_Reco=(TH1F*) InFileEta.Get("h_Reco");

TH1F * h_SF_2D=(TH1F*) InFileEta.Get("h_SF_pythia");
h_SF_2D->Clone("h_SFstat_ET_eta_mcatnlo");
h_SF_2D->Clone("h_SFstat_ET_eta_pythia");
h_SF_2D->Clone("h_SF_ET_eta_mcatnlo");
h_SF_2D->Clone("h_SF_ET_eta_pythia");
TH2F * reco_pythia_ET_Eta = h_SF_ET_eta_pythia->Clone("reco_pythia_ET_Eta");
TH2F * reco_mcatnlo_ET_Eta = h_SF_ET_eta_mcatnlo->Clone("reco_mcatnlo_ET_Eta");

int nEtBin=h_SF_ET_mcatnlo->GetNbinsX();
int nEtaBin=h_SF_eta_mcatnlo->GetNbinsX();

int crack1=h_SFstat_eta_mcatnlo->FindBin(1.4);
int crack2=h_SFstat_eta_mcatnlo->FindBin(-1.4);

float mcDenom=0;
float mcNum=0;
float pyDenom=0;
float pyNum=0;
for (int iEtaBin=0;iEtaBin<nEtaBin;iEtaBin++){
  if(iEtaBin==crack1 || iEtaBin==crack2) continue;
  float c=h_SFstat_eta_mcatnlo->GetBinContent(iEtaBin+1);
  float e=h_SFstat_eta_mcatnlo->GetBinError(iEtaBin+1);
  mcNum+=c/(e*e);
  mcDenom+=1./(e*e);
  c=h_SFstat_eta_pythia->GetBinContent(iEtaBin+1);
  e=h_SFstat_eta_pythia->GetBinError(iEtaBin+1);
  pyNum+=c/(e*e);
  pyDenom+=1./(e*e);
}
float mcNorm=mcNum/mcDenom;
float pyNorm=pyNum/pyDenom;

cout << "Normalizations: mc@nlo: " << mcNorm << " pythia: "  << pyNorm << endl;

for (int iEtBin=0;iEtBin<nEtBin;iEtBin++){
  float mc_c_et=h_SF_ET_mcatnlo->GetBinContent(iEtBin+1);
  float mc_e_et=h_SF_ET_mcatnlo->GetBinError(iEtBin+1);
  float mc_es_et=h_SFstat_ET_mcatnlo->GetBinError(iEtBin+1);
  float py_c_et=h_SF_ET_pythia->GetBinContent(iEtBin+1);
  float py_e_et=h_SF_ET_pythia->GetBinError(iEtBin+1);
  float py_es_et=h_SFstat_ET_pythia->GetBinError(iEtBin+1);
  
  for (iEtaBin=0;iEtaBin<nEtaBin;iEtaBin++){
    float mc_c_eta=h_SF_eta_mcatnlo->GetBinContent(iEtaBin+1);
    float mc_e_eta=h_SF_eta_mcatnlo->GetBinError(iEtaBin+1);
    float mc_es_eta=h_SFstat_eta_mcatnlo->GetBinError(iEtaBin+1);
    float py_c_eta=h_SF_eta_pythia->GetBinContent(iEtaBin+1);
    float py_e_eta=h_SF_eta_pythia->GetBinError(iEtaBin+1);
    float py_es_eta=h_SFstat_eta_pythia->GetBinError(iEtaBin+1);
	float reco_c_eta=h_Reco->GetBinContent(iEtaBin+1);
	float reco_es_eta=h_Reco->GetBinError(iEtaBin+1);
    //
	reco_pythia_ET_Eta->SetBinContent(iEtBin+1,iEtaBin+1,reco_c_eta*py_c_et*py_c_eta/pyNorm);
	reco_pythia_ET_Eta->SetBinError(iEtBin+1,iEtaBin+1,sqrt((py_e_et/py_c_et)*(py_e_et/py_c_et)+(py_e_eta/py_c_eta)*(py_e_eta/py_c_eta)+(reco_es_eta/reco_c_eta)*(reco_es_eta/reco_c_eta))/pyNorm);
    reco_mcatnlo_ET_Eta->SetBinContent(iEtBin+1,iEtaBin+1,reco_c_eta*mc_c_et*mc_c_eta/mcNorm);
	reco_mcatnlo_ET_Eta->SetBinError(iEtBin+1,iEtaBin+1,sqrt((mc_e_et/mc_c_et)*(mc_e_et/mc_c_et)+(mc_e_eta/mc_c_eta)*(mc_e_eta/mc_c_eta)+(reco_es_eta/reco_c_eta)*(reco_es_eta/reco_c_eta))/mcNorm);
    h_SF_ET_eta_mcatnlo->SetBinContent(iEtBin+1,iEtaBin+1,mc_c_et*mc_c_eta/mcNorm);
    h_SF_ET_eta_pythia->SetBinContent(iEtBin+1,iEtaBin+1,py_c_et*py_c_eta/pyNorm);
    h_SFstat_ET_eta_mcatnlo->SetBinContent(iEtBin+1,iEtaBin+1,mc_c_et*mc_c_eta/mcNorm);
    h_SFstat_ET_eta_pythia->SetBinContent(iEtBin+1,iEtaBin+1,py_c_et*py_c_eta/pyNorm);
    h_SF_ET_eta_mcatnlo->SetBinError(iEtBin+1,iEtaBin+1,sqrt((mc_e_et/mc_c_et)*(mc_e_et/mc_c_et)+(mc_e_eta/mc_c_eta)*(mc_e_eta/mc_c_eta))/mcNorm);
    h_SF_ET_eta_pythia->SetBinError(iEtBin+1,iEtaBin+1,sqrt((py_e_et/py_c_et)*(py_e_et/py_c_et)+(py_e_eta/py_c_eta)*(py_e_eta/py_c_eta))/pyNorm);
    h_SFstat_ET_eta_mcatnlo->SetBinError(iEtBin+1,iEtaBin+1,sqrt((mc_es_et/mc_c_et)*(mc_es_et/mc_c_et)+(mc_es_eta/mc_c_eta)*(mc_es_eta/mc_c_eta))/mcNorm);
    h_SFstat_ET_eta_pythia->SetBinError(iEtBin+1,iEtaBin+1,sqrt((py_es_et/py_c_et)*(py_es_et/py_c_et)+(py_es_eta/py_c_eta)*(py_es_eta/py_c_eta))/pyNorm);    
  }
}

reco_pythia_ET_Eta->Write();
reco_mcatnlo_ET_Eta->Write();
h_SF_ET_eta_mcatnlo->Write();
h_SF_ET_eta_pythia->Write();
h_SFstat_ET_eta_mcatnlo->Write();
h_SFstat_ET_eta_pythia->Write();
//
h_SF_ET_mcatnlo->Write();
h_SF_ET_pythia->Write();
h_SFstat_ET_mcatnlo->Write();
h_SFstat_ET_pythia->Write();
//
h_SF_eta_mcatnlo->Write();
h_SF_eta_pythia->Write();
h_SFstat_eta_mcatnlo->Write();
h_SFstat_eta_pythia->Write();

OutFile.Save();

}
