  #include "Riostream.h"
  void DYEffiPlots_Mar18(int which){

  gROOT->LoadMacro("atlasstyle-00-03-04/AtlasStyle.C");
  SetAtlasStyle();
  gStyle->SetOptFit(1111);
  gStyle->SetOptStat(0);
  gROOT->ForceStyle();
  
  float yminEff=0.7; //0;
  float ymaxEff=1.05; //1.5;
  float yminMCEff=0.7; //0;
  float ymaxMCEff=1.05; //1.5;
  float yminSoBMed=0;
  float ymaxSoBMed=1000;
  float yminSoBTrkQ=0;
  float ymaxSoBTrkQ=200; // 1000;
  float yminSF=0.8; //0;
  float ymaxSF=1.2; //1.5;
  float yminSF0=0.9; //0.;
  float ymaxSF0=1.05; //1.5;
  int whichCut=6;
  
  string prefix="";   
  const int nFile=2;
  ifstream file[nFile];
  string fileName[nFile] = {"",""};
  string fileName0[nFile] = {"",""};
  float nbin=0;
  
      if(which==1){
          prefix="Eta_6_40GeV_blayer_";
          fileName[0]="eta_TagIso_40GeV_blayer.txt";
          fileName[1]="eta_TagNonIso_40GeV_blayer.txt";
          fileName0[0]="Eta_TightIsoTag_40GeV_blayer";
          fileName0[1]="Eta_TightTag_40GeV_blayer";
          nbin=11;
      } else if(which==2){
          prefix="Eta_6_medium_40GeV_";
          fileName[0]="eta_TagIso_40GeV.txt";
          fileName[1]="eta_TagNonIso_40GeV.txt";
          fileName0[0]="Eta_TightIsoTag_40GeV";
          fileName0[1]="Eta_TightTag_40GeV";
          nbin=11;
      } else if(which==3){
          prefix="ET_6_noCrack_blayer_";
          fileName[0]="TagIso_noCrack_blayer.txt";
          fileName[1]="TagNonIso_noCrack_blayer.txt";
          fileName0[0]="ET_TightIsoTag_noCrack_blayer";
          fileName0[1]="ET_TightTag_noCrack_blayer";
          nbin=9;
      } else if(which==4){
          prefix="ET_6_medium_noCrack_";
          fileName[0]="TagIso_noCrack.txt";
          fileName[1]="TagNonIso_noCrack.txt";
          fileName0[0]="ET_TightIsoTag_noCrack";
          fileName0[1]="ET_TightTag_noCrack";  
          nbin=9; 
      } else {
          cout << "Choose 1-4!" << endl;
          return;
      }
    
  for (int iFile=0;iFile<nFile;iFile++){
    cout << "which=" << which << "  prefix=" << prefix << "  filename=" << fileName[iFile] << "  fileName0=" << fileName0[iFile] << "  nbin=" << nbin << endl;
  }
  
  const int nEtBin=nbin;
  float etBin[nEtBin+1];
  
  if(which==3 || which==4){
    etBin[0]=20;
    etBin[1]=25;
    etBin[2]=30;
    etBin[3]=35;
    etBin[4]=40;
    etBin[5]=45;
    etBin[6]=50;
    etBin[7]=80;
    etBin[8]=150;
    etBin[9]=500;
  } else if(which==1 || which==2){
/*    etBin[0]=-2.47;
    etBin[1]=-2.37;
    etBin[2]=-2.01;
    etBin[3]=-1.81;
    etBin[4]=-1.52;
    etBin[5]=-1.37;
    etBin[6]=-1.15;
    etBin[7]=-0.8;
    etBin[8]=-0.6;
    etBin[9]=-0.1;
    etBin[10]=0;
    etBin[11]=0.1;
    etBin[12]=0.6;
    etBin[13]=0.8;
    etBin[14]=1.15;
    etBin[15]=1.37;
    etBin[16]=1.52;
    etBin[17]=1.81;
    etBin[18]=2.01;
    etBin[19]=2.37;
    etBin[20]=2.47;
    float etBin20[nEtBin+1];
    etBin20[0]=-247;
    etBin20[1]=-237;
    etBin20[2]=-201;
    etBin20[3]=-181;
    etBin20[4]=-152;
    etBin20[5]=-137;
    etBin20[6]=-115;
    etBin20[7]=-80;
    etBin20[8]=-60;
    etBin20[9]=-10;
    etBin20[10]=0;
    etBin20[11]=10;
    etBin20[12]=60;
    etBin20[13]=80;
    etBin20[14]=115;
    etBin20[15]=137;
    etBin20[16]=152;
    etBin20[17]=181;
    etBin20[18]=201;
    etBin20[19]=237;
    etBin20[20]=247;
    TH1F etHisto20("etHisto20","ET",nEtBin,etBin20);*/
	etBin[0]=-2.47;
	etBin[1]=-2.01;
	etBin[2]=-1.52;
    etBin[3]=-1.37;
	etBin[4]=-0.8;
	etBin[5]=-0.1;
    etBin[6]=0.1;
    etBin[7]=0.8;
    etBin[8]=1.37;
    etBin[9]=1.52;
    etBin[10]=2.01;
    etBin[11]=2.47;
	float etBin11[nEtBin+1];
	etBin11[0]=-247;
	etBin11[1]=-201;
	etBin11[2]=-152;
    etBin11[3]=-137;
	etBin11[4]=-80;
	etBin11[5]=-10;
    etBin11[6]=10;
    etBin11[7]=80;
    etBin11[8]=137;
    etBin11[9]=152;
    etBin11[10]=201;
    etBin11[11]=247;
	TH1F etHisto11("etHisto11","ET",nEtBin,etBin11);
  }  
  TH1F etHisto("etHisto","ET",nEtBin,etBin);
  cout << "Binning:";
  for (int iEtBin=0;iEtBin<nEtBin+1;iEtBin++){
    cout << " " << etBin[iEtBin];  
  }
  cout << endl;

  const int nSelCut=6;
  string selCut[nSelCut+1] = {"_AllMee", "_AllMee_OS", 
                          "_PeakMee", "_PeakMee_OS", 
			  "_HighMee", "_HighMee_OS",
			  "_Everything"};
			  
  const int nIsoVar=2;
  string isoVar[nIsoVar] = {"_ETCone30", "_ETCone40"};
			  
  const int nIsoCut=3;
  string isoCut[nIsoCut] = {"_15GeV", "_17.5GeV", "_20GeV"};
			  			  
  const int nIsoTempl=6;
  string isoTempl[nIsoTempl] = {"_fside", "_fside+!TRT", "_!Trackmatch",
                              "_fsideFromJets","_SS+!loose","_!wstot+!TRT+rphi"};
			  

  int iIsoVar, iSelCut, iIsoCut, iIsoTempl, iEtBin;
  int xEtBin;
  float sTrkQ[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float sTrkQ_err[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float sMed[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float sMed_err[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float bTrkQ[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float bTrkQ_err[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float sTrkQ0[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float sTrkQ0_err[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float bMed[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float bMed_err[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float sMed0[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float sMed0_err[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float Eff[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float Eff_err[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  //float mcTrkQ[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  //float mcTrkQ_err[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  //float mcMed[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  //float mcMed_err[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float mcEff[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float mcEff_err[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float pyEff[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float pyEff_err[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float mcSF[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float mcSF_err[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float pySF[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];
  float pySF_err[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nEtBin][nFile];

  for (int iFile=0;iFile<nFile;iFile++){
    file[iFile].open(fileName[iFile].c_str(),ifstream::in);
    int nLine=0;
    cout << "Read file " << iFile << " " << fileName[iFile] << " " << fileName0[iFile] << endl;	        
    while(true){  
      //cout << "  Read line " << nLine << endl; 
      file[iFile] >> iIsoVar >> iSelCut >> iIsoCut >> iIsoTempl >> xEtBin;
      if(!file[iFile].good()){
        cout << endl;
	break;
      }
	  //cout << " nEtBin " << nEtBin << endl;
      if(nEtBin!=11) iEtBin=etHisto.FindBin(xEtBin)-1;
      else iEtBin=etHisto11.FindBin(xEtBin>=0 ? xEtBin : xEtBin+1)-1;
      //cout << "    IsoVar: " << iIsoVar << " " << isoVar[iIsoVar] << endl;	        
      //cout << "    SelCut: " << iSelCut << " " << selCut[iSelCut] << endl;	        
      //cout << "    IsoCut: " << iIsoCut << " " << isoCut[iIsoCut] << endl;	        
      //cout << "    IsoTempl: " << iIsoTempl << " " << isoTempl[iIsoTempl] << endl;	        
      //cout << "    EtBin: " << xEtBin << " " << iEtBin << " " << etBin[iEtBin] << endl;	        
      file[iFile] >> sTrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >> 
                  sTrkQ_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >>  // nprobe, nprobe_err
                  sMed[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >> 
		  sMed_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >>  // nsig, nsig_err
                  bTrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >> 
		  bTrkQ_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >>  // nprobe_bkgTh, nprobe_bkgTh_err
                  sTrkQ0[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >> 
		  sTrkQ0_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >>   // nprobe_sigTh, nprobe_sigTh_err
                  bMed[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >> 
		  bMed_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >>  // nsig_bkgTh, nsig_bkgTh_err
                  sMed0[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >> 
		  sMed0_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >>  // nsig_sigTh, nsig_sigTh_err
                  Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >> 
		  Eff_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >>  // eff_data, eff_data_err
                 // mcTrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >> 
		 // mcTrkQ_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >> 
                 // mcMed[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >> 
		 // mcMed_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >> 
                  mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >> 
		  mcEff_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >>  // eff_mcatnlo, eff_mcatnlo_err
                  pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >> 
		  pyEff_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >>  // eff_pythia, eff_pythia_err
                  mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >> 
		  mcSF_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >>  // sf_mcatnlo, sf_mcatnlo_err
                  pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] >> 
		  pySF_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile];   // sf_pythia, sf_pythia_err
      nLine++;
    }
    cout << "Lines read : " << nLine << " expected: " << nIsoVar*nSelCut*nIsoCut*nIsoTempl*nEtBin <<endl;
  }
   
  TH1F* h_Eff[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nFile];
  TH1F* h_mcEff[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nFile];
  TH1F* h_mcSF[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nFile];
  TH1F* h_pyEff[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nFile];
  TH1F* h_pySF[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nFile];
  TH1F* h_SoB_TrkQ[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nFile];
  TH1F* h_SoB_Med[nIsoVar][nSelCut][nIsoCut][nIsoTempl][nFile];
      
      TH1F* isoth[nIsoCut];
      TH1F* tmpl[nIsoTempl];
      TH1F* select[nSelCut];
      TH1F* etcone[nIsoVar];

  float meanSFmc[nEtBin][nSelCut+1], meanSFmc_err[nEtBin][nSelCut+1], rmsSFmc[nEtBin][nSelCut+1];
  float meanSFpy[nEtBin][nSelCut+1], meanSFpy_err[nEtBin][nSelCut+1], rmsSFpy[nEtBin][nSelCut+1];
  int count[nEtBin][nSelCut+1];
  for (int iEtBin=0;iEtBin<nEtBin;iEtBin++){
    for (int iSelCut=0;iSelCut<nSelCut+1;iSelCut++){
      meanSFmc[iEtBin][iSelCut]=0;
      meanSFmc_err[iEtBin][iSelCut]=0;
      rmsSFmc[iEtBin][iSelCut]=0;
      meanSFpy[iEtBin][iSelCut]=0;
      meanSFpy_err[iEtBin][iSelCut]=0;
      rmsSFpy[iEtBin][iSelCut]=0;
      count[iEtBin][iSelCut]=0;
    }
  }
  
  for(int iFile=0;iFile<nFile;iFile++){
    for(int iSelCut=0;iSelCut<nSelCut;iSelCut++){
      for(int iIsoVar=0;iIsoVar<nIsoVar;iIsoVar++){
        for(int iIsoCut=0;iIsoCut<nIsoCut;iIsoCut++){
          for(int iIsoTempl=0;iIsoTempl<nIsoTempl;iIsoTempl++){
	    string name = "Eff_" + fileName0[iFile] + selCut[iSelCut] + isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	//    cout << name << endl;
	    h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] = new TH1F(name.c_str(),"",nEtBin,etBin);
	    name = "mcEff_" + fileName0[iFile] + selCut[iSelCut] + isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	    h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] = new TH1F(name.c_str(),"",nEtBin,etBin);
	    name = "mcSF_" + fileName0[iFile] + selCut[iSelCut] + isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	    h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] = new TH1F(name.c_str(),"",nEtBin,etBin);
	    name = "pyEff_" + fileName0[iFile] + selCut[iSelCut] + isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	    h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] = new TH1F(name.c_str(),"",nEtBin,etBin);
	    name = "pySF_" + fileName0[iFile] + selCut[iSelCut] + isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	    h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] = new TH1F(name.c_str(),"",nEtBin,etBin);
	    name = "SoB_TrkQ" + fileName0[iFile] + selCut[iSelCut] + isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	    h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] = new TH1F(name.c_str(),"",nEtBin,etBin);      
	    name = "SoB_Med" + fileName0[iFile] + selCut[iSelCut] + isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	    h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] = new TH1F(name.c_str(),"",nEtBin,etBin);      
	    for(int iEtBin=0;iEtBin<nEtBin;iEtBin++){
	      //
	      if(iSelCut<2 || iSelCut>3) continue;  // use only Zee
	      if(iEtBin<6 && iIsoTempl==5) continue;  // do not use wstot+ rphi+!rTRT template below 50 GeV
		  //if(iEtBin>5 && iIsoTempl==2) continue; //do not use !Trackmatch above 50 GeV
		  if(mcEff==-9999 || mcEff_err==-9999 || mcSF==-9999 || mcSF_err==-9999) continue;
	      if(nEtBin==11 && iIsoTempl==3) continue;  // do not use jet template for eta binning
	      if(iIsoVar==0 && iIsoTempl==3) continue;  // do not use jet template for ETcone30
	      if(iEtBin<6 && iIsoTempl==3) continue;  // do not use jet template below 50 GeV
		  if(nEtBin==11 && (iIsoTempl==0 || iIsoTempl==1 || iIsoTempl==2)) continue; // do not use fside & fside+!rTRT for eta binning
	      //cout << fileName0[iFile] << " " << iIsoVar << " " << iSelCut << " " << iIsoCut << " " << iIsoTempl << " " 
	      //     << iEtBin << " " << etBin[iEtBin] << endl;
              //if(iEtBin==0) cout << iIsoVar << " " << iSelCut << " " << iIsoCut << " " << iIsoTempl << " " 
	           //<< iEtBin << " " << etBin[iEtBin] << " " 
		   //<< sTrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " << sTrkQ_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " 
		   //<< bTrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " << bTrkQ_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " 
		   //<< sMed[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " << sMed_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " 
		   //<< bMed[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " << bMed_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " 
		   //<< Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " << Eff_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " "
		   //<< mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " << mcEff_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " 
		   //<< mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " << mcSF_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " "  
		   //<< pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " << pyEff_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << endl; //" " 
		   //<< pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " << pySF_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << endl;  
	      
	      float SoBTrkQ = bTrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]==0 ? -1 : 
	            sTrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]/bTrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile];
	      float SoBMed = bMed[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]==0 ? -1 : 
	            sMed[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]/bMed[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile];
              /*cout << etBin[iEtBin] << " " << iFile << " " << iIsoVar << " " << iSelCut << " " << iIsoCut << " " << iIsoTempl << " " 
		   << sTrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << "+-" << sTrkQ_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " 
		   << bTrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << "+-" << bTrkQ_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " 
		   << sMed[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << "+-" << sMed_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " 
		   << bMed[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << "+-" << bMed_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " 
		   << SoBTrkQ << " " << SoBMed << endl; */
              //
	      h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile]->SetBinContent(iEtBin+1,Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]);
              h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile]->SetBinError(iEtBin+1,Eff_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]);
              //
	      h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile]->SetBinContent(iEtBin+1,mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]);
              h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile]->SetBinError(iEtBin+1,mcEff_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]);
              //
	      h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile]->SetBinContent(iEtBin+1,mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]);
              h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile]->SetBinError(iEtBin+1,mcSF_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]);
              //
	      h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile]->SetBinContent(iEtBin+1,pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]);
              h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile]->SetBinError(iEtBin+1,pyEff_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]);
              //
	      h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile]->SetBinContent(iEtBin+1,pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]);
              h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile]->SetBinError(iEtBin+1,pySF_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]);
              //
	      h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile]->SetBinContent(iEtBin+1,SoBTrkQ);
	      float se=sTrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]==0 ? 1 : sTrkQ_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]/sTrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile];
	      float be=bTrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]==0 ? 1 : bTrkQ_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]/bTrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile];
	      float e=sqrt(se*se+be*be)*SoBTrkQ;
              h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile]->SetBinError(iEtBin+1,e);
	      //
              h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile]->SetBinContent(iEtBin+1,SoBMed);
	      se=sMed[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]==0 ? 1 : sMed_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]/sMed[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile];
	      be=bMed[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]==0 ? 1 : bMed_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]/bMed[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile];
	      e=sqrt(se*se+be*be)*SoBMed;
              h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile]->SetBinError(iEtBin+1,e);
              //
              /*cout << iFile << " " << iIsoVar << " " << iSelCut << " " << iIsoCut << " " << iIsoTempl << " " 
	           << iEtBin << " " << xEtBin[iEtBin] << " " 
		   << mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " 
		   << Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << " " 
		   << SF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile] << endl;   
              */
	      //
	      //cout << "Calculating..." << endl;
	      meanSFmc[iEtBin][iSelCut]+=mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile];
	      meanSFmc_err[iEtBin][iSelCut]+=mcSF_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile];
	      meanSFpy[iEtBin][iSelCut]+=pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile];
	      meanSFpy_err[iEtBin][iSelCut]+=pySF_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile];
	      count[iEtBin][iSelCut]++;
	      meanSFmc[iEtBin][nSelCut]+=mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile];
	      meanSFmc_err[iEtBin][nSelCut]+=mcSF_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile];
	      meanSFpy[iEtBin][nSelCut]+=pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile];
	      meanSFpy_err[iEtBin][nSelCut]+=pySF_err[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile];
	      count[iEtBin][nSelCut]++;
	      //cout << "...mean" << endl;
	    }
	 //   cout << "Next..." << endl;
	  }
	}
      }	    
    } 
    file[iFile].close(); 
  }  

  for (int iEtBin=0;iEtBin<nEtBin;iEtBin++){
    for(int iSelCut=0;iSelCut<nSelCut+1;iSelCut++){
      if(iSelCut<2 || (iSelCut>3 && iSelCut<nSelCut) ) continue;  // use only Zee
      //cout << "Number of measurements: " << etBin[iEtBin] << " " << iSelCut << " " << count[iEtBin][iSelCut] << endl;
      meanSFmc[iEtBin][iSelCut]=meanSFmc[iEtBin][iSelCut]/count[iEtBin][iSelCut];
      meanSFmc_err[iEtBin][iSelCut]=meanSFmc_err[iEtBin][iSelCut]/count[iEtBin][iSelCut];
      meanSFpy[iEtBin][iSelCut]=meanSFpy[iEtBin][iSelCut]/count[iEtBin][iSelCut];
      meanSFpy_err[iEtBin][iSelCut]=meanSFpy_err[iEtBin][iSelCut]/count[iEtBin][iSelCut];
    }
  }
  
  for(int iEtBin=0;iEtBin<nEtBin;iEtBin++){
    for(int iFile=0;iFile<nFile;iFile++){
      for(int iSelCut=0;iSelCut<nSelCut;iSelCut++){
	for(int iIsoVar=0;iIsoVar<nIsoVar;iIsoVar++){
          for(int iIsoCut=0;iIsoCut<nIsoCut;iIsoCut++){
            for(int iIsoTempl=0;iIsoTempl<nIsoTempl;iIsoTempl++){
	      if(iSelCut<2 || iSelCut>3) continue;  // use only Zee
	      //if(iIsoTempl==2) continue;  // do not use !Trackmatch template
		  if(iEtBin<6 && iIsoTempl==5) continue;  // do not use wstot+ rphi+!rTRT template below 50 GeV
		  //if(iEtBin>5 && iIsoTempl==2) continue; //do not use !Trackmatch above 50 GeV
		  if(mcEff==-9999 || mcEff_err==-9999 || mcSF==-9999 || mcSF_err==-9999) continue;
	      if(nEtBin==11 && iIsoTempl==3) continue;  // do not use jet template for eta binning
	      if(iIsoVar==0 && iIsoTempl==3) continue;  // do not use jet template for ETcone30
	      if(iEtBin<6 && iIsoTempl==3) continue;  // do not use jet template below 50 GeV
		  if(nEtBin==11 && (iIsoTempl==0 || iIsoTempl==1 || iIsoTempl==2)) continue; // do not use fside & fside+!rTRT for eta binning
	      rmsSFmc[iEtBin][iSelCut]+=(mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]-meanSFmc[iEtBin][iSelCut])
	                                *(mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]-meanSFmc[iEtBin][iSelCut]);
	      rmsSFpy[iEtBin][iSelCut]+=(pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]-meanSFpy[iEtBin][iSelCut])
	                                *(pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]-meanSFpy[iEtBin][iSelCut]);
	      rmsSFmc[iEtBin][nSelCut]+=(mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]-meanSFmc[iEtBin][nSelCut])
	                                *(mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]-meanSFmc[iEtBin][nSelCut]);
	      rmsSFpy[iEtBin][nSelCut]+=(pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]-meanSFpy[iEtBin][nSelCut])
	                                *(pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iEtBin][iFile]-meanSFpy[iEtBin][nSelCut]);
	      //cout << iEtBin << " " << etBin[iEtBin] << " " << rmsSFmc[iEtBin] << " " << rmsSFpy[iEtBin] << endl;
	    }
	  }
	}
      }	    
    }  
  }
  TH1F * mcSFm[nSelCut+1];
  TH1F * mcSFmS[nSelCut+1];
  TH1F * pySFm[nSelCut+1];
  TH1F * pySFmS[nSelCut+1];
  for(int iSelCut=0;iSelCut<nSelCut+1;iSelCut++){
    if(iSelCut<2 || (iSelCut>3 && iSelCut<nSelCut) ) continue;  // use only Zee
    string name="mcSFm" + selCut[iSelCut];
    mcSFm[iSelCut] = new TH1F(name.c_str(),"",nEtBin, etBin);
    name="mcSFmS" + selCut[iSelCut];
    mcSFmS[iSelCut] = new TH1F(name.c_str(),"",nEtBin, etBin);
    name="pySFm" + selCut[iSelCut];
    pySFm[iSelCut] = new TH1F(name.c_str(),"",nEtBin, etBin);
    name="pySFmS" + selCut[iSelCut];
    pySFmS[iSelCut] = new TH1F(name.c_str(),"",nEtBin, etBin);
    for (int iEtBin=0;iEtBin<nEtBin;iEtBin++){
      rmsSFmc[iEtBin][iSelCut]=sqrt(rmsSFmc[iEtBin][iSelCut]/count[iEtBin][iSelCut]);
      rmsSFpy[iEtBin][iSelCut]=sqrt(rmsSFpy[iEtBin][iSelCut]/count[iEtBin][iSelCut]);
      cout << "*** " << iEtBin << " " << etBin[iEtBin] << " " << iSelCut
           << " " << meanSFmc[iEtBin][iSelCut] << " " << meanSFpy[iEtBin][iSelCut] 
           << " " << rmsSFmc[iEtBin][iSelCut] << " " << rmsSFpy[iEtBin][iSelCut] 
           << " " << meanSFmc_err[iEtBin][iSelCut] << " " << meanSFpy_err[iEtBin][iSelCut] << endl;    
      mcSFm[iSelCut]->SetBinContent(iEtBin+1,meanSFmc[iEtBin][iSelCut]);
      mcSFm[iSelCut]->SetBinError(iEtBin+1,sqrt(meanSFmc_err[iEtBin][iSelCut]*meanSFmc_err[iEtBin][iSelCut]+rmsSFmc[iEtBin][iSelCut]*rmsSFmc[iEtBin][iSelCut]));
      mcSFmS[iSelCut]->SetBinContent(iEtBin+1,meanSFmc[iEtBin][iSelCut]);
      mcSFmS[iSelCut]->SetBinError(iEtBin+1,meanSFmc_err[iEtBin][iSelCut]);
      pySFm[iSelCut]->SetBinContent(iEtBin+1,meanSFpy[iEtBin][iSelCut]);
      pySFm[iSelCut]->SetBinError(iEtBin+1,sqrt(meanSFpy_err[iEtBin][iSelCut]*meanSFpy_err[iEtBin][iSelCut]+rmsSFpy[iEtBin][iSelCut]*rmsSFpy[iEtBin][iSelCut]));
      pySFmS[iSelCut]->SetBinContent(iEtBin+1,meanSFpy[iEtBin][iSelCut]);
      pySFmS[iSelCut]->SetBinError(iEtBin+1,meanSFpy_err[iEtBin][iSelCut]);
    }
  }
  
  cout << "Plot now..." << endl;
/*
  TCanvas cEff("cEff","",600,900);
  TPad pad1("pad1","",0.02,0.98,0.98,0.41);
  TPad pad2("pad2","",0.02,0.0.02,0.98,0.40);
      pad1.Draw();
      pad2.Draw();
 // cEff.Divide(1,2);
  TH1F hEff("Eff","",1,etBin[0],etBin[nEtBin]);
  hEff.SetMinimum(yminEff);
  hEff.SetMaximum(ymaxEff);
  if(nEtBin!=11) hEff.GetXaxis()->SetTitle("E_{T} [GeV]");
  else hEff.GetXaxis()->SetTitle("#eta");
  hEff.GetXaxis()->SetMoreLogLabels();
  if (which == 2 || which == 4 ) hEff.GetYaxis()->SetTitle("Medium Efficiency");
  else hEff.GetYaxis()->SetTitle("Medium+B-Layer Efficiency");
  for (int iPlot=-1;iPlot<nSelCut;iPlot++){
  //  cEff.cd(1);
      pad1.cd();
      if(nEtBin!=11) pad1->SetLogx();
//    if(nEtBin!=11) cEff_1->SetLogx();
      TLegend leg(0.1,0.,1.,1.);
//    TLegend leg(0.1,0.,0.5,1.);
    leg.SetFillStyle(0);
    leg.SetBorderSize(0);
 //   TLegend leg1(0.6,0.,0.9,1.);
 //   leg1.SetFillStyle(0);
 //   leg1.SetBorderSize(0);
    hEff.Draw();
    for(int iFile=0;iFile<nFile;iFile++){
      for(int iSelCut=0;iSelCut<nSelCut;iSelCut++){
          string selname = selCut[iSelCut];
          select[iSelCut] = new TH1F(selname.c_str(),"",nEtBin,etBin);
          if(iSelCut<2 || iSelCut>3) continue;  // use only Zee
          select[iSelCut]->SetMarkerStyle(20+iSelCut);
          leg.AddEntry(select[iSelCut],selname.c_str(),"P");
	if(iPlot>=0 && iPlot<nSelCut && iSelCut!=iPlot) continue;
	for(int iIsoVar=0;iIsoVar<nIsoVar;iIsoVar++){
        string isoname = isoVar[iIsoVar];
        etcone[iIsoVar] = new TH1F(isoname.c_str(),"",nEtBin,etBin);
        etcone[iIsoVar]->SetLineWidth(iIsoVar+1);
        leg.AddEntry(etcone[iIsoVar],isoname.c_str(),"L");
          for(int iIsoCut=0;iIsoCut<nIsoCut;iIsoCut++){
            for(int iIsoTempl=0;iIsoTempl<nIsoTempl;iIsoTempl++){
          string tmplname = isoTempl[iIsoTempl];
          tmpl[iIsoTempl] = new TH1F(tmplname.c_str(),"",nEtBin,etBin);
	      //if(iIsoTempl==2) continue;  // do not use !Trackmatch template
		  if(nEtBin!=11 && iEtBin<6 && iIsoTempl==5) continue;  // do not use wstot+ rphi+!rTRT template below 50 GeV
		  //if(iEtBin>5 && iIsoTempl==2) continue; //do not use !Trackmatch above 50 GeV
	      if(nEtBin==11 && iIsoTempl==3) continue;  // do not use jet template for eta binning
	      if(iIsoVar==0 && iIsoTempl==3) continue;  // do not use jet template for ETcone30
	      if(nEtBin!=11 && iEtBin<6 && iIsoTempl==3) continue;  // do not use jet template below 50 GeV
	      if(nEtBin==11 && (iIsoTempl==0 || iIsoTempl==1 || iIsoTempl==2)) continue; // do not use fside & fside+!rTRT for eta binning
	      h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerSize(1.);
	      h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineColor(iIsoTempl+1);
	      h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerColor(iIsoTempl+1);
	      h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerStyle(20+iSelCut);
	      //h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineColor(iSelCut+1);
	      //h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerColor(iSelCut+1);
	      //h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerStyle(20+iIsoTempl);
	      h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineStyle(iIsoCut+1);
	      h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineWidth(iIsoVar+1);
	      h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> Draw("same");
	      //
	 //     string name = fileName0[iFile] + selCut[iSelCut] + isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	      //string name = isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	   //   if(iIsoVar==0) leg.AddEntry(h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile], name.c_str());
	   //   else leg1.AddEntry(h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile], name.c_str());
          tmpl[iIsoTempl]->SetMarkerColor(iIsoTempl+1);
          leg.AddEntry(tmpl[iIsoTempl],tmplname.c_str(),"F");
         //       }
            }
	  } 
	}
   }
    }
 //   cEff.cd(2);
      pad2.cd();
    leg.Draw();
 //   leg1.Draw();
    string name;
    if(iPlot==-1) name = prefix + "Eff.png";
    if(iPlot>=0 && iPlot<nSelCut) name = prefix + "Eff" + selCut[iPlot] + ".png";
    cEff.Print(name.c_str());
  }
  

  TCanvas cpyEff("cpyEff","",600,900);
  cpyEff.Divide(1,2);
  TH1F hpyEff("pyEff","",1,etBin[0],etBin[nEtBin]);
  hpyEff.SetMinimum(yminMCEff);
  hpyEff.SetMaximum(ymaxMCEff);
  if(nEtBin!=11) hpyEff.GetXaxis()->SetTitle("E_{T} [GeV]");
  else hpyEff.GetXaxis()->SetTitle("#eta");
  hpyEff.GetXaxis()->SetMoreLogLabels();
  hpyEff.GetYaxis()->SetTitle("Medium+B-Layer Pythia Efficiency");
  for (int iPlot=-1;iPlot<nSelCut;iPlot++){
    cpyEff.cd(1);
    if(nEtBin!=11) cpyEff_1->SetLogx();
    TLegend leg(0.1,0.,0.5,1.);
    leg.SetFillStyle(0);
    leg.SetBorderSize(0);
    TLegend leg1(0.6,0.,0.9,1.);
    leg1.SetFillStyle(0);
    leg1.SetBorderSize(0);
    hpyEff.Draw();
    for(int iFile=0;iFile<nFile;iFile++){
      for(int iSelCut=0;iSelCut<nSelCut;iSelCut++){
	if(iPlot>=0 && iPlot<nSelCut && iSelCut!=iPlot) continue;
	for(int iIsoVar=0;iIsoVar<nIsoVar;iIsoVar++){
          for(int iIsoCut=0;iIsoCut<nIsoCut;iIsoCut++){
            for(int iIsoTempl=0;iIsoTempl<nIsoTempl;iIsoTempl++){
	  //    if(iSelCut<2 || iSelCut>3) continue;  // use only Zee
	      //if(iIsoTempl==2) continue;  // do not use !Trackmatch template
		  if(iEtBin<6 && iIsoTempl==5) continue;  // do not use wstot+ rphi+!rTRT template below 50 GeV
		  //if(iEtBin>5 && iIsoTempl==2) continue; //do not use !Trackmatch above 50 GeV
	      if(nEtBin==11 && iIsoTempl==3) continue;  // do not use jet template for eta binning
	      if(iIsoVar==0 && iIsoTempl==3) continue;  // do not use jet template for ETcone30
	      if(nEtBin!=11 && iEtBin<6 && iIsoTempl==3) continue;  // do not use jet template below 50 GeV
	      if(nEtBin==11 && (iIsoTempl==0 || iIsoTempl==1 || iIsoTempl==2)) continue; // do not use fside & fside+!rTRT for eta binning
	      h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerSize(1.);
	      h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineColor(iIsoTempl+1);
	      h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerColor(iIsoTempl+1);
	      h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerStyle(20+iSelCut);
	      //h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineColor(iSelCut+1);
	      //h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerColor(iSelCut+1);
	      //h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerStyle(20+iIsoTempl);
	      h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineStyle(iIsoCut+1);
	      h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineWidth(iIsoVar+1);
	      h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> Draw("same");
	      //
	      string name = fileName0[iFile] + selCut[iSelCut] + isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	      //string name = isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	      if(iIsoVar==0) leg.AddEntry(h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile], name.c_str());
	      else leg1.AddEntry(h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile], name.c_str());
            }
	  } 
	}
      }
    }
    cpyEff.cd(2);
    leg.Draw();
    leg1.Draw();
    string name;
    if(iPlot==-1) name = prefix + "pyEff.png";
    if(iPlot>=0 && iPlot<nSelCut) name = prefix + "pyEff" + selCut[iPlot] + ".png";
    cpyEff.Print(name.c_str());
  }

  TCanvas cmcEff("cmcEff","",600,900);
  cmcEff.Divide(1,2);
  TH1F hmcEff("mcEff","",1,etBin[0],etBin[nEtBin]);
  hmcEff.SetMinimum(yminMCEff);
  hmcEff.SetMaximum(ymaxMCEff);
  if(nEtBin!=11) hmcEff.GetXaxis()->SetTitle("E_{T} [GeV]");
  else hmcEff.GetXaxis()->SetTitle("#eta");
  hmcEff.GetXaxis()->SetMoreLogLabels();
  hmcEff.GetYaxis()->SetTitle("Medium+B-Layer MC@NLO Efficiency");
  for (int iPlot=-1;iPlot<nSelCut;iPlot++){
    cmcEff.cd(1);
    if(nEtBin!=11) cmcEff_1->SetLogx();
    TLegend leg(0.1,0.,0.5,1.);
    leg.SetFillStyle(0);
    leg.SetBorderSize(0);
    TLegend leg1(0.6,0.,0.9,1.);
    leg1.SetFillStyle(0);
    leg1.SetBorderSize(0);
    hmcEff.Draw();
    for(int iFile=0;iFile<nFile;iFile++){
      for(int iSelCut=0;iSelCut<nSelCut;iSelCut++){
	if(iPlot>=0 && iPlot<nSelCut && iSelCut!=iPlot) continue;
	for(int iIsoVar=0;iIsoVar<nIsoVar;iIsoVar++){
          for(int iIsoCut=0;iIsoCut<nIsoCut;iIsoCut++){
            for(int iIsoTempl=0;iIsoTempl<nIsoTempl;iIsoTempl++){
	      if(iSelCut<2 || iSelCut>3) continue;  // use only Zee
		  if(mcEff==-9999 || mcEff_err==-9999 || mcSF==-9999 || mcSF_err==-9999) continue;
	      //if(iIsoTempl==2) continue;  // do not use !Trackmatch template
		  if(nEtBin!=11 && iEtBin<6 && iIsoTempl==5) continue;  // do not use wstot+ rphi+!rTRT template below 50 GeV
		  //if(iEtBin>5 && iIsoTempl==2) continue; //do not use !Trackmatch above 50 GeV
	      if(nEtBin==11 && iIsoTempl==3) continue;  // do not use jet template for eta binning
	      if(iIsoVar==0 && iIsoTempl==3) continue;  // do not use jet template for ETcone30
	      if(nEtBin!=11 && iEtBin<6 && iIsoTempl==3) continue;  // do not use jet template below 50 GeV
	      if(nEtBin==11 && (iIsoTempl==0 || iIsoTempl==1 || iIsoTempl==2)) continue; // do not use fside & fside+!rTRT for eta binning
	      h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerSize(1.);
	      h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineColor(iIsoTempl+1);
	      h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerColor(iIsoTempl+1);
	      h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerStyle(20+iSelCut);
	      //h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineColor(iSelCut+1);
	      //h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerColor(iSelCut+1);
	      //h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerStyle(20+iIsoTempl);
	      h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineStyle(iIsoCut+1);
	      h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineWidth(iIsoVar+1);
	      h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> Draw("same");
	      //
	      string name = fileName0[iFile] + selCut[iSelCut] + isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	      //string name = isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	      if(iIsoVar==0) leg.AddEntry(h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile], name.c_str());
	      else leg1.AddEntry(h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile], name.c_str());
            }
	  } 
	}
      }
    }
    cmcEff.cd(2);
    leg.Draw();
    leg1.Draw();
    string name;
    if(iPlot==-1) name = prefix + "mcEff.png";
    if(iPlot>=0 && iPlot<nSelCut) name = prefix + "mcEff" + selCut[iPlot] + ".png";
    cmcEff.Print(name.c_str());
  }
  
  TCanvas cSoB_Med("cSoB_Med","",600,900);
  cSoB_Med.Divide(1,2);
  TH1F hSoB_Med("SoB_Med","",1,etBin[0],etBin[nEtBin]);
  hSoB_Med.SetMinimum(yminSoBMed);
  hSoB_Med.SetMaximum(ymaxSoBMed);
  if(nEtBin!=11) hSoB_Med.GetXaxis()->SetTitle("E_{T} [GeV]");
  else hSoB_Med.GetXaxis()->SetTitle("#eta");
  hSoB_Med.GetXaxis()->SetMoreLogLabels();
  if (which == 2 || which == 4 ) hSoB_Med.GetYaxis()->SetTitle("S/B after Medium");
  hSoB_Med.GetYaxis()->SetTitle("S/B after Medium+B-Layer");
  for (int iPlot=-1;iPlot<nSelCut;iPlot++){
    cSoB_Med.cd(1);
    if(nEtBin!=11) cSoB_Med_1->SetLogx();
    TLegend leg(0.1,0.,0.5,1.);
    leg.SetFillStyle(0);
    leg.SetBorderSize(0);
    TLegend leg1(0.6,0.,0.9,1.);
    leg1.SetFillStyle(0);
    leg1.SetBorderSize(0);
    hSoB_Med.Draw();
    for(int iFile=0;iFile<nFile;iFile++){
      for(int iSelCut=0;iSelCut<nSelCut;iSelCut++){
	if(iPlot>=0 && iPlot<nSelCut && iSelCut!=iPlot) continue;
	for(int iIsoVar=0;iIsoVar<nIsoVar;iIsoVar++){
          for(int iIsoCut=0;iIsoCut<nIsoCut;iIsoCut++){
            for(int iIsoTempl=0;iIsoTempl<nIsoTempl;iIsoTempl++){
	      if(iSelCut<2 || iSelCut>3) continue;  // use only Zee
	      //if(iIsoTempl==2) continue;  // do not use !Trackmatch template
		  if(nEtBin!=11 && iEtBin<6 && iIsoTempl==5) continue;  // do not use wstot+ rphi+!rTRT template below 50 GeV
		  //if(iEtBin>5 && iIsoTempl==2) continue; //do not use !Trackmatch above 50 GeV
	      if(nEtBin==11 && iIsoTempl==3) continue;  // do not use jet template for eta binning
	      if(iIsoVar==0 && iIsoTempl==3) continue;  // do not use jet template for ETcone30
	      if(nEtBin!=11 && iEtBin<6 && iIsoTempl==3) continue;  // do not use jet template below 50 GeV
	      if(nEtBin==11 && (iIsoTempl==0 || iIsoTempl==1 || iIsoTempl==2)) continue; // do not use fside & fside+!rTRT for eta binning
	      h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerSize(1.);
	      h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineColor(iIsoTempl+1);
	      h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerColor(iIsoTempl+1);
	      h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerStyle(20+iSelCut);
	      //h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineColor(iSelCut+1);
	      //h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerColor(iSelCut+1);
	      //h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerStyle(20+iIsoTempl);
	      h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineStyle(iIsoCut+1);
	      h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineWidth(iIsoVar+1);
	      h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> Draw("same");
	      //
	      string name = fileName0[iFile] + selCut[iSelCut] + isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	      //string name = isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	      if(iIsoVar==0) leg.AddEntry(h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile], name.c_str());
	      else leg1.AddEntry(h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile], name.c_str());
            }
	  } 
	}
      }
    }
    cSoB_Med.cd(2);
    leg.Draw();
    leg1.Draw();
    string name;
    if(iPlot==-1) name = prefix + "SoB_Med.png";
    if(iPlot>=0 && iPlot<nSelCut) name = prefix + "SoB_Med" + selCut[iPlot] + ".png";
    cSoB_Med.Print(name.c_str());
  }
  
  TCanvas cSoB_TRkQ("cSoB_TRkQ","",600,900);
  cSoB_TRkQ.Divide(1,2);
  TH1F hSoB_TRkQ("SoB_TRkQ","",1,etBin[0],etBin[nEtBin]);
  hSoB_TRkQ.SetMinimum(yminSoBTrkQ);
  hSoB_TRkQ.SetMaximum(ymaxSoBTrkQ);
  if(nEtBin!=11) hSoB_TRkQ.GetXaxis()->SetTitle("E_{T} [GeV]");
  else hSoB_TRkQ.GetXaxis()->SetTitle("#eta");
  hSoB_TRkQ.GetXaxis()->SetMoreLogLabels();
  hSoB_TRkQ.GetYaxis()->SetTitle("S/B after TrkQ");
  for (int iPlot=-1;iPlot<nSelCut;iPlot++){
    cSoB_TRkQ.cd(1);
    if(nEtBin!=11) cSoB_TRkQ_1->SetLogx();
    TLegend leg(0.1,0.,0.5,1.);
    leg.SetFillStyle(0);
    leg.SetBorderSize(0);
    TLegend leg1(0.6,0.,0.9,1.);
    leg1.SetFillStyle(0);
    leg1.SetBorderSize(0);
    hSoB_TRkQ.Draw();
    for(int iFile=0;iFile<nFile;iFile++){
      for(int iSelCut=0;iSelCut<nSelCut;iSelCut++){
	if(iPlot>=0 && iPlot<nSelCut && iSelCut!=iPlot) continue;
	for(int iIsoVar=0;iIsoVar<nIsoVar;iIsoVar++){
          for(int iIsoCut=0;iIsoCut<nIsoCut;iIsoCut++){
            for(int iIsoTempl=0;iIsoTempl<nIsoTempl;iIsoTempl++){
	      if(iSelCut<2 || iSelCut>3) continue;  // use only Zee
	      //if(iIsoTempl==2) continue;  // do not use !Trackmatch template
		  if(nEtBin!=11 && iEtBin<6 && iIsoTempl==5) continue;  // do not use wstot+ rphi+!rTRT template below 50 GeV
		  //if(iEtBin>5 && iIsoTempl==2) continue; //do not use !Trackmatch above 50 GeV
	      if(nEtBin==20 && iIsoTempl==3) continue;  // do not use jet template for eta binning
	      if(iIsoVar==0 && iIsoTempl==3) continue;  // do not use jet template for ETcone30
	      if(nEtBin!=11 && iEtBin<6 && iIsoTempl==3) continue;  // do not use jet template below 50 GeV
	      if(nEtBin==11 && (iIsoTempl==0 || iIsoTempl==1 || iIsoTempl==2)) continue; // do not use fside & fside+!rTRT for eta binning
	      h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerSize(1.);
	      h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineColor(iIsoTempl+1);
	      h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerColor(iIsoTempl+1);
	      h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerStyle(20+iSelCut);
	      //h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineColor(iSelCut+1);
	      //h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerColor(iSelCut+1);
	      //h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerStyle(20+iIsoTempl);
	      h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineStyle(iIsoCut+1);
	      h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineWidth(iIsoVar+1);
	      h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> Draw("same");
	      //
	      string name = fileName0[iFile] + selCut[iSelCut] + isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	      //string name = isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	      if(iIsoVar==0) leg.AddEntry(h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile], name.c_str());
	      else leg1.AddEntry(h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile], name.c_str());
            }
	  } 
	}
      }
    }
    cSoB_TRkQ.cd(2);
    leg.Draw();
    leg1.Draw();
    string name;
    if(iPlot==-1) name = prefix + "SoB_TRkQ.png";
    if(iPlot>=0 && iPlot<nSelCut) name = prefix + "SoB_TRkQ" + selCut[iPlot] + ".png";
    cSoB_TRkQ.Print(name.c_str());
  }

  TCanvas cpySF("cpySF","",600,900);
  cpySF.Divide(1,2);
  TH1F hpySF("pySF","",1,etBin[0],etBin[nEtBin]);
  hpySF.SetMinimum(yminSF);
  hpySF.SetMaximum(ymaxSF);
  if(nEtBin!=11) hpySF.GetXaxis()->SetTitle("E_{T} [GeV]");
  else hpySF.GetXaxis()->SetTitle("#eta");
  hpySF.GetXaxis()->SetMoreLogLabels();
  hpySF.GetYaxis()->SetTitle("S/B after TrkQ");
  for (int iPlot=-1;iPlot<nSelCut;iPlot++){
    cpySF.cd(1);
    if(nEtBin!=11) cpySF_1->SetLogx();
    TLegend leg(0.1,0.,0.5,1.);
    leg.SetFillStyle(0);
    leg.SetBorderSize(0);
    TLegend leg1(0.6,0.,0.9,1.);
    leg1.SetFillStyle(0);
    leg1.SetBorderSize(0);
    hpySF.Draw();
    for(int iFile=0;iFile<nFile;iFile++){
      for(int iSelCut=0;iSelCut<nSelCut;iSelCut++){
	if(iPlot>=0 && iPlot<nSelCut && iSelCut!=iPlot) continue;
	for(int iIsoVar=0;iIsoVar<nIsoVar;iIsoVar++){
          for(int iIsoCut=0;iIsoCut<nIsoCut;iIsoCut++){
            for(int iIsoTempl=0;iIsoTempl<nIsoTempl;iIsoTempl++){
	      if(iSelCut<2 || iSelCut>3) continue;  // use only Zee
	      //if(iIsoTempl==2) continue;  // do not use !Trackmatch template
		  if(nEtBin!=11 && iEtBin<6 && iIsoTempl==5) continue;  // do not use wstot+ rphi+!rTRT template below 50 GeV
		  //if(iEtBin>5 && iIsoTempl==2) continue; //do not use !Trackmatch above 50 GeV
	      if(nEtBin==20 && iIsoTempl==3) continue;  // do not use jet template for eta binning
	      if(iIsoVar==0 && iIsoTempl==3) continue;  // do not use jet template for ETcone30
	      if(nEtBin!=11 && iEtBin<6 && iIsoTempl==3) continue;  // do not use jet template below 50 GeV
	      if(nEtBin==11 && (iIsoTempl==0 || iIsoTempl==1 || iIsoTempl==2)) continue; // do not use fside & fside+!rTRT for eta binning
	      h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerSize(1.);
	      h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineColor(iIsoTempl+1);
	      h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerColor(iIsoTempl+1);
	      h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerStyle(20+iSelCut);
	      //h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineColor(iSelCut+1);
	      //h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerColor(iSelCut+1);
	      //h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerStyle(20+iIsoTempl);
	      h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineStyle(iIsoCut+1);
	      h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineWidth(iIsoVar+1);
	      h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> Draw("same");
	      //
	      string name = fileName0[iFile] + selCut[iSelCut] + isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	      //string name = isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	      if(iIsoVar==0) leg.AddEntry(h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile], name.c_str());
	      else leg1.AddEntry(h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile], name.c_str());
            }
	  } 
	}
      }
    }
    cpySF.cd(2);
    leg.Draw();
    leg1.Draw();
    string name;
    if(iPlot==-1) name = prefix + "pySF.png";
    if(iPlot>=0 && iPlot<nSelCut) name = prefix + "pySF" + selCut[iPlot] + ".png";
    cpySF.Print(name.c_str());
  }

  TCanvas cmcSF("cmcSF","",600,900);
  cmcSF.Divide(1,2);
  TH1F hmcSF("mcSF","",1,etBin[0],etBin[nEtBin]);
  hmcSF.SetMinimum(yminSF);
  hmcSF.SetMaximum(ymaxSF);
  if(nEtBin!=11) hmcSF.GetXaxis()->SetTitle("E_{T} [GeV]");
  else hmcSF.GetXaxis()->SetTitle("#eta");
  hmcSF.GetXaxis()->SetMoreLogLabels();
  hmcSF.GetYaxis()->SetTitle("S/B after TrkQ");
  for (int iPlot=-1;iPlot<nSelCut;iPlot++){
    cmcSF.cd(1);
    if(nEtBin!=11) cmcSF_1->SetLogx();
    TLegend leg(0.1,0.,0.5,1.);
    leg.SetFillStyle(0);
    leg.SetBorderSize(0);
    TLegend leg1(0.6,0.,0.9,1.);
    leg1.SetFillStyle(0);
    leg1.SetBorderSize(0);
    hmcSF.Draw();
    for(int iFile=0;iFile<nFile;iFile++){
      for(int iSelCut=0;iSelCut<nSelCut;iSelCut++){
	if(iPlot>=0 && iPlot<nSelCut && iSelCut!=iPlot) continue;
	for(int iIsoVar=0;iIsoVar<nIsoVar;iIsoVar++){
          for(int iIsoCut=0;iIsoCut<nIsoCut;iIsoCut++){
            for(int iIsoTempl=0;iIsoTempl<nIsoTempl;iIsoTempl++){
	      if(iSelCut<2 || iSelCut>3) continue;  // use only Zee
		  if(mcEff==-9999 || mcEff_err==-9999 || mcSF==-9999 || mcSF_err==-9999) continue;
	      //if(iIsoTempl==2) continue;  // do not use !Trackmatch template
		  if(nEtBin!=11 && iEtBin<6 && iIsoTempl==5) continue;  // do not use wstot+ rphi+!rTRT template below 50 GeV
		  //if(iEtBin>5 && iIsoTempl==2) continue; //do not use !Trackmatch above 50 GeV
	      if(nEtBin==20 && iIsoTempl==3) continue;  // do not use jet template for eta binning
	      if(iIsoVar==0 && iIsoTempl==3) continue;  // do not use jet template for ETcone30
	      if(nEtBin!=11 && iEtBin<6 && iIsoTempl==3) continue;  // do not use jet template below 50 GeV
	      if(nEtBin==11 && (iIsoTempl==0 || iIsoTempl==1 || iIsoTempl==2)) continue; // do not use fside & fside+!rTRT for eta binning
	      h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerSize(1.);
	      h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineColor(iIsoTempl+1);
	      h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerColor(iIsoTempl+1);
	      h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerStyle(20+iSelCut);
	      //h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineColor(iSelCut+1);
	      //h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerColor(iSelCut+1);
	      //h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetMarkerStyle(20+iIsoTempl);
	      h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineStyle(iIsoCut+1);
	      h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> SetLineWidth(iIsoVar+1);
	      h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile] -> Draw("same");
	      //
	      string name = fileName0[iFile] + selCut[iSelCut] + isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	      //string name = isoVar[iIsoVar] + isoCut[iIsoCut] + isoTempl[iIsoTempl];
	      if(iIsoVar==0) leg.AddEntry(h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile], name.c_str());
	      else leg1.AddEntry(h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile], name.c_str());
            }
	  } 
	}
      }
    }
    cmcSF.cd(2);
    leg.Draw();
    leg1.Draw();
    string name;
    if(iPlot==-1) name = prefix + "mcSF.png";
    if(iPlot>=0 && iPlot<nSelCut) name = prefix + "mcSF" + selCut[iPlot] + ".png";
    cmcSF.Print(name.c_str());
  }
*/
  float m_11Etabins[12] = {-2.47,-2.01,-1.52,-1.37,-0.8,-0.1,0.1,0.8,1.37,1.52,2.01,2.47}; 
  float shift=0.03;
  float m_11Etabins_1[12] = {-2.47-shift,-2.01-shift,-1.52-shift,-1.37-shift,-0.8-shift,-0.1-shift,0.1-shift,0.8-shift,1.37-shift,1.52-shift,2.01-shift,2.47-shift}; 
   float m_11Etabins_2[12] = {-2.47+shift,-2.01+shift,-1.52+shift,-1.37+shift,-0.8+shift,-0.1+shift,0.1+shift,0.8+shift,1.37+shift,1.52+shift,2.01+shift,2.47+shift};

  float sfMedium_Combined_Moriond_eta[11] = {0.980389, 0.984739, 0.987, 0.995007, 0.992199, 0.999625, 0.992335, 0.991465, 0.9896, 0.990364, 0.982351};
  float errsfMedium_Combined_Moriond_eta[11] = {0.0187827, 0.01235, 0.00807527, 0.00418403, 0.0044624, 0.00429145, 0.00446588, 0.00383729, 0.00793473, 0.0138236, 0.0179662};
  float sfMedium_Jpsi_Moriond_eta[11] = {0.942597, 0.974524, 1.08641, 1.01779, 0.975308, 0.97664, 0.982064, 0.971485, 1.07755, 0.981647, 0.910087};
  float errsfMedium_Jpsi_Moriond_eta[11] = {0.042, 0.085, 0.091, 0.049, 0.028, 0.03, 0.028, 0.049, 0.095, 0.06, 0.049};
    
  float m_ETbinsFullRange[11] = {0, 7, 10, 15, 20, 25, 30, 35, 40, 45, 50};
  float sfMedium_Combined_Moriond_pt[10] = {0., 1.02283, 0.980082, 0.954413, 0.950976, 0.982899, 0.998409, 1.00998, 1.00825, 1.00394};
  float errsfMedium_Combined_Moriond_pt[10] = {1., 0.0562668, 0.0482163, 0.0225589, 0.0206991, 0.00776764, 0.00602853, 0.00685129, 0.00541447, 0.00645837};

//  float m_ETbinsUnnormalized[7] = {20, 25, 30, 35, 40, 45, 50};
  float Sf_Medium_Pt[7]={ 96.02, 96.32, 98.54, 99.16, 99.77, 99.86, 100.10};
  float Sf_Medium_Pt_err[7]={ 1.34, 0.78, 0.49, 0.23, 0.15, 0.13, 0.13};
  float Sf_Medium_Eta[11]={ 99.29, 99.84, 98.71, 99.26, 99.57, 100.28, 99.75, 98.78, 99.20, 100.31, 99.71};
  float Sf_Medium_Eta_err[11]={ 0.32, 0.45, 0.44, 0.18, 0.22, 0.27, 0.17, 0.19, 0.47, 0.37, 0.38};
  
// combined moriond, W + Z T&P  
  float sfMedium_W_Moriond_pt[7] = {0.945357, 0.942763, 0.975195, 0.998875, 1.01063, 1.00875, 1.00316};
  float errsfMedium_W_Moriond_pt[7] = {0.0294631, 0.0223839, 0.00859636, 0.00379292, 0.0021063, 0.0021702, 0.00496909};
  float sfMedium_Z_Moriond_pt[7] = {0.965405, 0.966607, 0.989958, 0.996673, 1.00218, 1.00269, 1.00559};
  float errsfMedium_Z_Moriond_pt[7] = {0.0328278, 0.0308792, 0.00822904, 0.00732296, 0.0072506, 0.00719009, 0.00719009};
  
  float sfMedium_W_Moriond_eta[11] = {0.959084, 0.976819, 0, 0.994861, 0.988635, 0.997058, 0.988179, 0.991838, 0, 0.980873, 0.964391};
  float errsfMedium_W_Moriond_eta[11] = {0.00942027, 0.00606207, 1000, 0.0051154, 0.00561657, 0.00523272, 0.00565839, 0.00451729, 1000, 0.00602941, 0.00844241};
  float sfMedium_Z_Moriond_eta[11] = {0.9947, 0.9995, 0.987, 0.9953, 0.9983, 1.0049, 0.9992, 0.9905, 0.9896, 1.0068, 0.9984};
  float errsfMedium_Z_Moriond_eta[11] = {0.00772075, 0.00827587, 0.00807527, 0.00727255, 0.00734847, 0.0075, 0.00727255, 0.00727255, 0.00793473, 0.00793473, 0.0079806};

  float xAxis0[11] = {15,20,25,30,35,40,45,50,80,150,500};
  float off = 0.8;
  float xAxis0_1[11] = {15-off,20-off,25-off,30-off,35-off,40-off,45-off,50-off,80-off,150-off,500-off}; 
  float xAxis0_1[11] = {15+off,20+off,25+off,30+off,35+off,40+off,45+off,50+off,80+off,150+off,500+off}; 
  TH1F egamma("egamma","Medium efficiencies",10, xAxis0);
  TH1F egammaETA("egammaETA","Medium efficiencies",11,m_11Etabins_1);
  if(nEtBin!=11) {
    for (int i=2; i<8;i++){
      cout << i+2 << " " << m_ETbinsFullRange[i+2] << " " << sfMedium_Combined_Moriond_pt[i+2] << " " << errsfMedium_Combined_Moriond_pt[i+2] << endl; 
      egamma.SetBinContent(i,sfMedium_Combined_Moriond_pt[i+2]);
      egamma.SetBinError(i,errsfMedium_Combined_Moriond_pt[i+2]);
    }  
  } else {
    for (int i=0; i<11;i++){
      cout << i << " eta = " << m_11Etabins[i] << " - " << m_11Etabins[i+1] << " : " 
           << sfMedium_Combined_Moriond_eta[i] << " " << errsfMedium_Combined_Moriond_eta[i] << endl; 
      egammaETA.SetBinContent(i+1,sfMedium_Combined_Moriond_eta[i]);
      egammaETA.SetBinError(i+1,errsfMedium_Combined_Moriond_eta[i]);
    }  
  
  }
  egamma.SetMarkerColor(kBlack);
  egamma.SetMarkerStyle(29);
  egamma.SetMarkerSize(2.0);
  egamma.SetLineColor(kBlack);
  egammaETA.SetMarkerColor(kBlack);
  egammaETA.SetMarkerStyle(29);
  egammaETA.SetMarkerSize(2.0);
  egammaETA.SetLineColor(kBlack);
  
  TH1F egamma_Z("egamma_Z","Medium efficiencies",10, xAxis0);
  TH1F egammaETA_Z("egammaETA_Z","Medium efficiencies",11,m_11Etabins_2);
  TH1F egamma_W_moriond("egamma_W_moriond","Medium efficiencies",10, xAxis0);
  TH1F egammaETA_W_moriond("egammaETA_W_moriond","Medium efficiencies",11,m_11Etabins_1);
  TH1F egamma_Z_moriond("egamma_Z_moriond","Medium efficiencies",10, xAxis0);
  TH1F egammaETA_Z_moriond("egammaETA_Z_moriond","Medium efficiencies",11,m_11Etabins_2);
   if(nEtBin!=11) {
     for(int i=1; i<8;i++) {
	   egamma_Z.SetBinContent(i+1,Sf_Medium_Pt[i]/100);
	   egamma_Z.SetBinError(i+1,Sf_Medium_Pt_err[i]/100);
	   egamma_W_moriond.SetBinContent(i+1,sfMedium_W_Moriond_pt[i]);
	   egamma_W_moriond.SetBinError(i+1,errsfMedium_W_Moriond_pt[i]);
	   egamma_Z_moriond.SetBinContent(i+1,sfMedium_Z_Moriond_pt[i]);
	   egamma_Z_moriond.SetBinError(i+1,errsfMedium_Z_Moriond_pt[i]);
      }
   }
   else {
    for (int i=0; i<11;i++){
      cout << i << " eta = " << m_11Etabins[i] << " - " << m_11Etabins[i+1] << " : " 
           << sfMedium_Combined_Moriond_eta[i] << " " << errsfMedium_Combined_Moriond_eta[i] << endl; 
      egammaETA_Z.SetBinContent(i+1,Sf_Medium_Eta[i]/100);
      egammaETA_Z.SetBinError(i+1,Sf_Medium_Eta_err[i]/100);
	  egammaETA_W_moriond.SetBinContent(i+1,sfMedium_W_Moriond_eta[i]);
      egammaETA_W_moriond.SetBinError(i+1,errsfMedium_W_Moriond_eta[i]);
	  egammaETA_Z_moriond.SetBinContent(i+1,sfMedium_Z_Moriond_eta[i]);
      egammaETA_Z_moriond.SetBinError(i+1,errsfMedium_Z_Moriond_eta[i]);
    }  

   }
  egamma_Z.SetMarkerColor(kGray+2);
  egamma_Z.SetMarkerStyle(33);
  egamma_Z.SetMarkerSize(2.0);
  egamma_Z.SetLineColor(kGray+2);
  egamma_Z.SetLineStyle(kDashed);
  egamma_W_moriond.SetMarkerColor(kGreen+3);
  egamma_W_moriond.SetMarkerStyle(24);
  egamma_W_moriond.SetMarkerSize(1.5);
  egamma_W_moriond.SetLineColor(kGreen+3);
  egamma_W_moriond.SetLineStyle(kDashed); 
  egamma_Z_moriond.SetMarkerColor(kMagenta+2);
  egamma_Z_moriond.SetMarkerStyle(26);
  egamma_Z_moriond.SetMarkerSize(1.5);
  egamma_Z_moriond.SetLineColor(kMagenta+2);
  egamma_Z_moriond.SetLineStyle(kDashed); 
  egammaETA_Z.SetMarkerColor(kGray+2);
  egammaETA_Z.SetMarkerStyle(33);
  egammaETA_Z.SetMarkerSize(2.0);
  egammaETA_Z.SetLineColor(kGray+2);
  egammaETA_Z.SetLineStyle(kDashed);
  egammaETA_W_moriond.SetMarkerColor(kGreen+3);
  egammaETA_W_moriond.SetMarkerStyle(24);
  egammaETA_W_moriond.SetMarkerSize(1.5);
  egammaETA_W_moriond.SetLineColor(kGreen+3);
  egammaETA_W_moriond.SetLineStyle(kDashed);
  egammaETA_Z_moriond.SetMarkerColor(kMagenta+2);
  egammaETA_Z_moriond.SetMarkerStyle(26);
  egammaETA_Z_moriond.SetMarkerSize(1.5);
  egammaETA_Z_moriond.SetLineColor(kMagenta+2);
  egammaETA_Z_moriond.SetLineStyle(kDashed);

  TLegend leg(0.2,0.6,0.75,0.9);
  leg.SetFillStyle(0);
  leg.SetBorderSize(0);
      if (which == 2 || which == 4) {
  if(nEtBin!=11) {
    // leg.AddEntry(&egamma, "EGamma combined");
	 leg.AddEntry(&egamma_Z, "e/#gamma Z T&P");
//	 leg.AddEntry(&egamma_W_moriond, "egamma W T&P Moriond");
//	 leg.AddEntry(&egamma_Z_moriond, "egamma Z T&P Moriond");
	}
  else {
     leg.AddEntry(&egammaETA, "e/#gamma combined");
     leg.AddEntry(&egammaETA_Z, "e/#gamma Z T&P");
//	 leg.AddEntry(&egammaETA_W_moriond, "egamma W T&P Moriond");
//	 leg.AddEntry(&egammaETA_Z_moriond, "egamma Z T&P Moriond");
    }
      }
  TCanvas cSF1("cSF1");
  if(nEtBin!=11) cSF1.SetLogx();
  TH1F hSF1("hSF1","",1,etBin[0],etBin[nEtBin]);
//  hSF1.SetMinimum(yminSF0);
//  hSF1.SetMaximum(ymaxSF0);
  if(nEtBin==11)    hSF1.SetMinimum(95);
      else hSF1.SetMinimum(92);
    hSF1.SetMaximum(102);
  if(nEtBin!=11) hSF1.GetXaxis()->SetTitle("E_{T} [GeV]");
  else hSF1.GetXaxis()->SetTitle("#eta");
  hSF1.GetXaxis()->SetMoreLogLabels();
      if(which==1 || which==3){
  hSF1.GetYaxis()->SetTitle("Medium+B-Layer Scale Factor [%]");
      } else {
  hSF1.GetYaxis()->SetTitle("Medium Scale Factor [%]");
      }
      
  hSF1.Draw();
  hSF1.Draw();
  for(iSelCut=0;iSelCut<nSelCut+1;iSelCut++){
    //if(iSelCut<2 || (iSelCut>3 && iSelCut<nSelCut)) continue;
    if(iSelCut!=nSelCut) continue;
    int style = kDashed;
    if(iSelCut==nSelCut) style = kSolid;
    if(iSelCut%2==1) style = kDotted;     
    pySFm[iSelCut]->SetLineStyle(style);  
    pySFm[iSelCut]->SetLineColor(kRed+2);
    pySFm[iSelCut]->SetMarkerColor(kRed+2);
    pySFm[iSelCut]->SetMarkerStyle(27-iSelCut);
    pySFmS[iSelCut]->SetLineStyle(style);  
    pySFmS[iSelCut]->SetLineColor(kRed);
    pySFmS[iSelCut]->SetMarkerColor(kRed);
    pySFmS[iSelCut]->SetMarkerStyle(27-iSelCut);
      pySFm[iSelCut]->Scale(100);
      pySFmS[iSelCut]->Scale(100);
    pySFm[iSelCut]->Draw("same E1");
    pySFmS[iSelCut]->Draw("same E1");
    mcSFm[iSelCut]->SetLineStyle(style);  
    mcSFm[iSelCut]->SetLineColor(kBlue+2);
    mcSFm[iSelCut]->SetMarkerColor(kBlue+2);
    mcSFm[iSelCut]->SetMarkerStyle(26-iSelCut);  
    mcSFmS[iSelCut]->SetLineStyle(style);
    mcSFmS[iSelCut]->SetLineColor(kBlue);
    mcSFmS[iSelCut]->SetMarkerColor(kBlue);
    mcSFmS[iSelCut]->SetMarkerStyle(26-iSelCut);
      mcSFm[iSelCut]->Scale(100);
    mcSFmS[iSelCut]->Scale(100);
    mcSFm[iSelCut]->Draw("same E1");
    mcSFmS[iSelCut]->Draw("same E1");
      string pytitle = "DY T&P PYTHIA ";// + selCut[iSelCut];
      string mctitle = "DY T&P MC@NLO ";// + selCut[iSelCut];
//    string pytitle = "DY T&P (Pythia) " + selCut[iSelCut];
//    string mctitle = "DY T&P (MC@NLO) " + selCut[iSelCut];
    leg.AddEntry(pySFmS[iSelCut], pytitle.c_str());
    leg.AddEntry(mcSFmS[iSelCut], mctitle.c_str());
  }
      if (which == 2 || which == 4) {
  if(nEtBin!=11)  {
      egamma.Scale(100);
      egamma_Z.Scale(100);
    //egamma.Draw("same");
	egamma_Z.Draw("same");
//	egamma_W_moriond.Draw("same");
//	egamma_Z_moriond.Draw("same");
	}
  else {
      egammaETA.Scale(100);
      egammaETA_Z.Scale(100);
    egammaETA.Draw("same");
	egammaETA_Z.Draw("same");
//	egammaETA_W_moriond.Draw("same");
//	egammaETA_Z_moriond.Draw("same");
	}
      }
  leg.Draw();

  TLine l(etBin[0],100,etBin[nEtBin],100);
  l.Draw();
  string name = prefix + "SFmean.png";
  cSF1.Print(name.c_str());

  cout << "Making SF rootfile: ";

  const int nEtBin=9;
  float etBin[nEtBin+1] = {20,25,30,35,40,45,50,80,150,500};
  const int nEtaBin=11;
  float etaBin[nEtaBin+1] = {-2.47,-2.01,-1.52,-1.37,-0.8,-0.1,
                             0.1,0.8,1.37,1.52,2.01,2.47};		

  const double Sf_RecoTrkQ_Eta[]={ 102.01, 100.67, 100.97, 100.17, 99.40, 99.16, 99.25, 100.13, 100.73, 100.57, 102.30};
  const double Sf_RecoTrkQ_Eta_err[]={ 0.70, 0.57, 0.70, 0.57, 1.11, 1.16, 0.99, 0.55, 0.90, 0.60, 0.71};
  const double Sf_RecoTrkQ_Eta_syst[]={ 0.66, 0.53, 0.60, 0.55, 1.11, 1.14, 0.98, 0.53, 0.81, 0.56, 0.67};
  const double Sf_RecoTrkQ_Eta_stat[]={ 0.22, 0.21, 0.37, 0.14, 0.12, 0.20, 0.12, 0.14, 0.39, 0.22, 0.22};
  
  string name=prefix + selCut[whichCut] + "_SF.root";
  cout << name << endl;
  TFile OutFile(name.c_str(),"RECREATE");
  TH2F h_SFstat_mcatnlo("h_SFstat_mcatnlo","mcatnlo ET-eta SF",nEtBin,etBin,nEtaBin,etaBin);
  TH2F h_SFstat_pythia("h_SFstat_pythia","Pythia ET-eta SF",nEtBin,etBin,nEtaBin,etaBin);
  TH1F h_SFstat_ET_mcatnlo("h_SFstat_ET_mcatnlo","mcatnlo ET SF",nEtBin,etBin);
  TH1F h_SFstat_ET_pythia("h_SFstat_ET_pythia","Pythia ET SF",nEtBin,etBin);
  TH1F h_SFstat_eta_mcatnlo("h_SFstat_eta_mcatnlo","mcatnlo eta SF",nEtaBin,etaBin);
  TH1F h_SFstat_eta_pythia("h_SFstat_eta_pythia","Pythia eta SF",nEtaBin,etaBin);
  TH2F h_SF_mcatnlo("h_SF_mcatnlo","mcatnlo ET-eta SF",nEtBin,etBin,nEtaBin,etaBin);
  TH2F h_SF_pythia("h_SF_pythia","Pythia ET-eta SF",nEtBin,etBin,nEtaBin,etaBin);
  TH1F h_SF_ET_mcatnlo("h_SF_ET_mcatnlo","mcatnlo ET SF",nEtBin,etBin);
  TH1F h_SF_ET_pythia("h_SF_ET_pythia","Pythia ET SF",nEtBin,etBin);
  TH1F h_SF_eta_mcatnlo("h_SF_eta_mcatnlo","mcatnlo eta SF",nEtaBin,etaBin);
  TH1F h_SF_eta_pythia("h_SF_eta_pythia","Pythia eta SF",nEtaBin,etaBin);
  TH1F h_Reco("h_Reco","Reco SF",nEtaBin,etaBin);
  TH2F h_RecoID_combined("h_RecoID_combined"," Reco and ID SF combined",nEtBin,etBin,nEtaBin,etaBin);
  if(which==3 || which==4) {
    for (int iEtBin=0;iEtBin<nEtBin;iEtBin++){
      h_SFstat_ET_mcatnlo.SetBinContent(iEtBin+1,meanSFmc[iEtBin][whichCut]);
      h_SFstat_ET_mcatnlo.SetBinError(iEtBin+1,meanSFmc_err[iEtBin][whichCut]);
      h_SFstat_ET_pythia.SetBinContent(iEtBin+1,meanSFpy[iEtBin][whichCut]);
      h_SFstat_ET_pythia.SetBinError(iEtBin+1,meanSFpy_err[iEtBin][whichCut]); 
      h_SF_ET_mcatnlo.SetBinContent(iEtBin+1,meanSFmc[iEtBin][whichCut]);
      h_SF_ET_mcatnlo.SetBinError(iEtBin+1,sqrt(meanSFmc_err[iEtBin][whichCut]*meanSFmc_err[iEtBin][whichCut]+rmsSFmc[iEtBin][whichCut]*rmsSFmc[iEtBin][whichCut]));
      h_SF_ET_pythia.SetBinContent(iEtBin+1,meanSFpy[iEtBin][whichCut]);
      h_SF_ET_pythia.SetBinError(iEtBin+1,sqrt(meanSFpy_err[iEtBin][whichCut]*meanSFpy_err[iEtBin][whichCut]+rmsSFpy[iEtBin][whichCut]*rmsSFpy[iEtBin][whichCut])); 
      for (int iEtaBin=0;iEtaBin<nEtaBin;iEtaBin++){
	h_SFstat_mcatnlo.SetBinContent(iEtBin+1,iEtaBin+1,meanSFmc[iEtBin][whichCut]);
	h_SFstat_mcatnlo.SetBinError(iEtBin+1,iEtaBin+1,meanSFmc_err[iEtBin][whichCut]);
	h_SFstat_pythia.SetBinContent(iEtBin+1,iEtaBin+1,meanSFpy[iEtBin][whichCut]);
	h_SFstat_pythia.SetBinError(iEtBin+1,iEtaBin+1,meanSFpy_err[iEtBin][whichCut]);
	h_SF_mcatnlo.SetBinContent(iEtBin+1,iEtaBin+1,meanSFmc[iEtBin][whichCut]);
	h_SF_mcatnlo.SetBinError(iEtBin+1,iEtaBin+1,sqrt(meanSFmc_err[iEtBin][whichCut]*meanSFmc_err[iEtBin][whichCut]+rmsSFmc[iEtBin][whichCut]*rmsSFmc[iEtBin][whichCut]));
	h_SF_pythia.SetBinContent(iEtBin+1,iEtaBin+1,meanSFpy[iEtBin][whichCut]);
	h_SF_pythia.SetBinError(iEtBin+1,iEtaBin+1,sqrt(meanSFpy_err[iEtBin][whichCut]*meanSFpy_err[iEtBin][whichCut]+rmsSFpy[iEtBin][whichCut]*rmsSFpy[iEtBin][whichCut]));
	h_RecoID_combined.SetBinContent(iEtBin+1,iEtaBin+1,Sf_RecoTrkQ_Eta[iEtaBin]*meanSFpy[iEtBin][whichCut]);
	h_RecoID_combined.SetBinError(iEtBin+1,iEtaBin+1,sqrt(meanSFpy_err[iEtBin][whichCut]*meanSFpy_err[iEtBin][whichCut]+rmsSFpy[iEtBin][whichCut]*rmsSFpy[iEtBin][whichCut]+Sf_RecoTrkQ_Eta_err[iEtaBin]*Sf_RecoTrkQ_Eta_err[iEtaBin]));
      }
    }  
  } else if(which==1 || which==2) {
    for (int iEtaBin=0;iEtaBin<nEtaBin;iEtaBin++){
      h_SFstat_eta_mcatnlo.SetBinContent(iEtaBin+1,meanSFmc[iEtaBin][whichCut]);
      h_SFstat_eta_mcatnlo.SetBinError(iEtaBin+1,meanSFmc_err[iEtaBin][whichCut]);
      h_SFstat_eta_pythia.SetBinContent(iEtaBin+1,meanSFpy[iEtaBin][whichCut]);
      h_SFstat_eta_pythia.SetBinError(iEtaBin+1,meanSFpy_err[iEtaBin][whichCut]);
      h_SF_eta_mcatnlo.SetBinContent(iEtaBin+1,meanSFmc[iEtaBin][whichCut]);
      h_SF_eta_mcatnlo.SetBinError(iEtaBin+1,sqrt(meanSFmc_err[iEtaBin][whichCut]*meanSFmc_err[iEtaBin][whichCut]+rmsSFmc[iEtaBin][whichCut]*rmsSFmc[iEtaBin][whichCut]));
      h_SF_eta_pythia.SetBinContent(iEtaBin+1,meanSFpy[iEtaBin][whichCut]);
      h_SF_eta_pythia.SetBinError(iEtaBin+1,sqrt(meanSFpy_err[iEtaBin][whichCut]*meanSFpy_err[iEtaBin][whichCut]+rmsSFpy[iEtaBin][whichCut]*rmsSFpy[iEtaBin][whichCut]));
	  h_Reco.SetBinContent(iEtaBin+1,Sf_RecoTrkQ_Eta[iEtaBin]);
	  h_Reco.SetBinError(iEtaBin+1,Sf_RecoTrkQ_Eta_err[iEtaBin]);
    }
  }
  h_SFstat_mcatnlo.Write();
  h_SFstat_pythia.Write();
  h_SFstat_ET_mcatnlo.Write();
  h_SFstat_ET_pythia.Write();
  h_SFstat_eta_mcatnlo.Write();
  h_SFstat_eta_pythia.Write();
  h_SF_mcatnlo.Write();
  h_SF_pythia.Write();
  h_SF_ET_mcatnlo.Write();
  h_SF_ET_pythia.Write();
  h_SF_eta_mcatnlo.Write();
  h_SF_eta_pythia.Write();
  h_Reco.Write();
  h_RecoID_combined.Write();
  
  OutFile.Save();
    
  cout << "All done" << endl;
  for(int iFile=0;iFile<nFile;iFile++){
    for(int iSelCut=0;iSelCut<nSelCut;iSelCut++){
      for(int iIsoVar=0;iIsoVar<nIsoVar;iIsoVar++){
        for(int iIsoCut=0;iIsoCut<nIsoCut;iIsoCut++){
          for(int iIsoTempl=0;iIsoTempl<nIsoTempl;iIsoTempl++){
	    delete h_Eff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile];
	    delete h_mcEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile];
	    delete h_pyEff[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile];
	    delete h_mcSF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile];
	    delete h_pySF[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile];
	    delete h_SoB_TrkQ[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile];
	    delete h_SoB_Med[iIsoVar][iSelCut][iIsoCut][iIsoTempl][iFile];
          }
	} 
      }
    }
  }
  for(int iSelCut=0;iSelCut<nSelCut+1;iSelCut++){
    delete mcSFm[iSelCut];
    delete mcSFmS[iSelCut];
    delete pySFm[iSelCut];
    delete pySFmS[iSelCut];
  }
  cout << "Booked areas deleted" << endl; 

}
