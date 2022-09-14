int plot() {
    TGraph *gr = new TGraph("output.txt","%*lg, %lg, %*lg, %lg, %*lg, %*lg");
    gr->Draw("A*");
    return 0;
}
