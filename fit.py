from ROOT import TFile,TF1,TH1F, TMath, gStyle,TLegend,TLatex
import math
from array import array
from numpy import *

f = TFile('ET_Eta_6_noCrack_40GeV_medium__Everything_SF.root')

pySF_ET_Eta = f.Get('h_SF_ET_eta_pythia')
pySF = pySF_ET_Eta.ProjectionX('pySF',11,11,'e')

ff1 = TF1('ff1','[0]',30,500)
#ff2 = TF1('ff2','[0]+x*[1]',45,500)
#ff3 = TF1('ff3','[0]+[1]*log(x)',25,500)
#ff4 = TF1('ff4','[0]+[1]*x*[2]',25,500)
ff2 = TF1('ff2','[0]',35,500)
ff3 = TF1('ff3','[0]',40,500)
ff4 = TF1('ff4','[0]',45,500)
ff5 = TF1('ff5','[0]',50,500)

pySF.Fit('ff1','R')
pySF.Fit('ff2','R')
pySF.Fit('ff3','R')
pySF.Fit('ff4','R')
pySF.Fit('ff5','R')

eg_SF_err = [0.0206991, 0.00776764, 0.00602853, 0.00685129, 0.00541447, 0.00645837]
eg_SF = [0.950976, 0.982899, 0.998409, 1.00998, 1.00825, 1.00394]
egamma = TH1F('egamma','',6,20,50)
for i in range(egamma.GetNbinsX()):
    egamma.SetBinContent(i+1,eg_SF[i])
    egamma.SetBinError(i+1,eg_SF_err[i])

dist = array([ff1.GetParameter(0),ff2.GetParameter(0),ff3.GetParameter(0),ff4.GetParameter(0),ff5.GetParameter(0)])
mean = dist.mean()
sig = dist.std()
print 'mean ', round(mean,5), ' sig ', round(sig,5), '\n'
print 'low: mean - 1sig: ', round(mean-sig,5), '\n'
print 'high: mean + 1sig: ', round(mean+sig,5), '\n'
print 'egamma low: - 1sig: ', 1.00394-0.00646, '\n' 
print 'egamma high: - 1sig: ', 1.00394+0.00646, '\n' 

print 'egamma last bin &', 1.00394, '$\pm$', 0.00646, '\\\\ \\hline \n'
print 'last bin DY &', round(pySF.GetBinContent(5),5), '$\pm$', round(pySF.GetBinError(5),5), '\\\\ \\hline \n'
print 'fit [30,500] GeV &', round(ff1.GetParameter(0),5), '$\pm$', round(ff1.GetParError(0),5), '\\\\ \\hline \n'
print 'fit [35,500] GeV &', round(ff2.GetParameter(0),5), '$\pm$', round(ff2.GetParError(0),5), '\\\\ \\hline \n'
print 'fit [40,500] GeV &', round(ff3.GetParameter(0),5), '$\pm$', round(ff3.GetParError(0),5), '\\\\ \\hline \n'
print 'fit [45,500] GeV &', round(ff4.GetParameter(0),5), '$\pm$', round(ff4.GetParError(0),5), '\\\\ \\hline \n'
print 'fit [50,500] GeV &', round(ff5.GetParameter(0),5), '$\pm$', round(ff5.GetParError(0),5), '\\\\ \\hline \n'

leg = TLegend(0.2,0.6,0.75,0.9)
leg.SetFillStyle(0)
leg.SetBorderSize(0)
leg.AddEntry(egamma,'egamma combined','lep')
leg.AddEntry(pySF,'DY Pythia','f')

myText = TLatex()
myText.SetNDC()
myText.SetTextColor(1)
myText.SetTextSize(0.04)

ff1.SetLineColor(2)
ff1.SetLineWidth(2)
ff2.SetLineColor(3)
ff2.SetLineWidth(2)
ff3.SetLineColor(4)
ff3.SetLineWidth(2)
ff4.SetLineColor(5)
ff4.SetLineWidth(2)
ff4.SetLineStyle(2)
ff5.SetLineWidth(2)
ff5.SetLineColor(6)
#pySF.SetFillStyle(3004)
pySF.SetMarkerStyle(22)
pySF.SetTitle('Normalized Pythia SF')
leg.Draw()
myText.DrawLatex(0.55,0.75,'#sqrt{s} = 7TeV, #int L =  4.92 fb^{-1}')
pySF.Draw('SAME')

egamma.SetMarkerStyle(30)
egamma.SetLineColor(8)
egamma.Draw('SAME')

ff1.Draw('4 SAME')
ff2.Draw('4 SAME')
ff3.Draw('4 SAME')
ff4.Draw('4 SAME')
ff5.Draw('4 SAME')

raw_input()
