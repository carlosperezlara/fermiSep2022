int plot(int sigma=0) {
    TGraph *gr;
    if(sigma==1) {
        gr = new TGraph("output.txt","%*lg, %*lg, %*lg, %*lg, %lg, %*lg, %lg, %*lg, %*lg");
    } else if(sigma==2) {
        gr = new TGraph("output.txt","%*lg, %*lg, %*lg, %*lg, %lg, %lg, %*lg, %*lg, %*lg");
    } else {
        gr = new TGraph("output.txt","%*lg, %*lg, %lg, %*lg, %lg, %*lg, %*lg, %*lg, %*lg");
    }
    gr->Draw("A*");
    if(sigma==0) {
        gr->GetXaxis()->SetTitle("VBias");
    } else {
        gr->GetXaxis()->SetTitle("Amplitude Buffered  (mV)");
    }
    if(sigma==0) {
        gr->GetYaxis()->SetTitle("Amplitude Buffered  (mV)");
    } else if(sigma==1) {
        gr->GetYaxis()->SetTitle("Sigma  (ns)");
    } else if(sigma==2) {
        gr->GetYaxis()->SetTitle("Mean  (ns)");
    }

    TGraph *rat = new TGraph();
    for(int i=0; i<gr->GetN()/2; ++i) {
        rat->SetPoint( i, gr->GetPointX(i*2), gr->GetPointY(i*2+1)/gr->GetPointY(i*2) );
    }
    new TCanvas();
    rat->Draw("A*");

    return 0;
}
