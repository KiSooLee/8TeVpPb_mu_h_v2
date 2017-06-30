# 8TeVpPb_mu_h_v2

1. pPb muon hadron correlation is using SingleMuon PD.

2. With the track multiplicity, muon pt, track pt binning tree is skimmed by Sort.C. In each binning total output files are 10 and contains 5000000 events for each output file.

3. To correlate background two input files with same component is needed. Copyroot.sh is used to copy root files.

4. dphi vs. deta distribution is ploted by Correl_sig.C and Correl_bkg.C

5. By accumulate dphi vs. deta histograms for each bin total dphi vs. deta distribution is achieved. And |eta| < 2 is projected to fitted by fourier series.
