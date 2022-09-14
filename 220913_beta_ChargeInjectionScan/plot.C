int plot(int sigma=1) {
    TGraph *gr;
    if(sigma==1) {
        gr = new TGraph("output.txt","%*lg, %lg, %*lg, %*lg, %*lg, %*lg, %lg, %*lg, %*lg");
    } else if(sigma==2) {
        gr = new TGraph("output.txt","%*lg, %lg, %*lg, %*lg, %*lg, %lg, %*lg, %*lg, %*lg");
    } else {
        gr = new TGraph("output.txt","%*lg, %lg, %*lg, %*lg, %lg, %*lg, %*lg, %*lg, %*lg");
    }
    gr->Draw("A*");
    gr->GetXaxis()->SetTitle("EffQ  (fC)");
    if(sigma==1) {
        gr->GetYaxis()->SetTitle("Sigma  (ns)");
    } else if(sigma==2) {
        gr->GetYaxis()->SetTitle("Mean  (ns)");
    } else {
        gr->GetYaxis()->SetTitle("Amplitude Buffered  (mV)");
    }
    return 0;
}
