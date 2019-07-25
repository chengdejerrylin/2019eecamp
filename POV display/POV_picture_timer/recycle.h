const int STRIPE_NUM = 64;
const byte lines[64][8][3] = {
{{0,129,13},{0,129,13},{0,129,13},{0,129,13},{0,129,13},{0,129,13},{0,129,13},{0,129,13}},
{{0,129,13},{0,129,13},{0,129,13},{0,129,13},{4,126,15},{1,129,10},{0,129,10},{0,128,17}},
{{5,126,10},{0,130,6},{18,127,18},{252,252,252},{251,253,250},{252,252,252},{229,249,222},{0,129,13}},
{{162,216,180},{0,122,11},{2,125,9},{252,253,245},{255,255,255},{255,255,255},{255,255,255},{0,129,13}},
{{255,255,255},{253,251,254},{213,247,210},{193,215,202},{255,255,255},{255,255,255},{252,254,253},{210,242,201}},
{{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{251,253,252}},
{{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255}},
{{8,118,19},{17,117,29},{40,114,55},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255}},
{{1,129,8},{21,103,29},{253,255,254},{255,255,255},{255,255,255},{255,255,255},{252,255,255},{4,126,17}},
{{18,134,7},{255,248,255},{251,253,252},{255,255,255},{255,255,255},{250,250,250},{4,128,8},{4,125,19}},
{{0,129,13},{0,130,8},{240,255,245},{252,252,252},{254,253,255},{1,129,8},{4,125,22},{0,129,13}},
{{0,129,13},{0,129,13},{0,129,13},{4,121,4},{236,254,240},{250,252,247},{1,128,11},{3,128,8}},
{{0,129,13},{0,129,13},{0,129,13},{0,129,13},{0,129,13},{14,121,7},{255,249,250},{14,135,29}},
{{0,129,15},{0,129,13},{0,129,13},{0,129,13},{0,129,13},{3,128,11},{36,110,35},{253,253,253}},
{{233,255,235},{38,119,40},{7,130,14},{0,129,13},{0,129,13},{0,129,13},{15,123,22},{255,255,255}},
{{255,255,255},{252,252,252},{180,220,183},{0,129,13},{0,129,13},{0,132,13},{69,146,78},{255,255,255}},
{{255,255,255},{255,255,250},{117,169,123},{0,129,13},{0,129,13},{0,132,13},{182,222,185},{255,255,255}},
{{255,255,255},{255,255,255},{166,202,174},{0,129,13},{0,129,13},{0,132,13},{69,146,78},{255,255,255}},
{{255,255,255},{255,255,255},{239,254,251},{1,128,13},{0,129,13},{0,129,13},{3,131,10},{255,251,252}},
{{255,255,255},{255,255,253},{250,250,252},{1,128,13},{0,129,13},{0,129,13},{4,127,11},{249,249,249}},
{{255,255,255},{255,255,253},{255,255,255},{27,119,34},{0,129,13},{0,129,13},{0,132,13},{3,124,11}},
{{255,255,255},{255,255,255},{253,253,253},{246,252,250},{0,129,13},{0,129,13},{0,129,13},{4,128,8}},
{{255,255,255},{255,255,255},{255,255,255},{253,253,241},{14,125,23},{0,129,13},{0,129,13},{1,128,11}},
{{255,255,255},{255,255,255},{252,255,251},{5,126,13},{0,129,13},{0,129,13},{0,129,13},{4,128,8}},
{{255,255,255},{213,255,211},{4,127,13},{4,127,13},{0,129,13},{0,129,13},{4,128,8},{244,249,245}},
{{252,255,251},{4,127,13},{4,127,13},{0,129,13},{1,128,13},{8,125,10},{252,252,252},{5,128,12}},
{{4,127,13},{4,127,13},{1,128,13},{1,128,13},{8,125,10},{252,252,252},{1,125,3},{7,125,3}},
{{1,127,17},{1,128,13},{0,129,13},{1,128,13},{252,252,252},{5,128,12},{8,133,5},{43,120,66}},
{{3,131,12},{0,129,13},{1,128,13},{78,140,89},{241,255,247},{2,123,17},{25,119,23},{109,210,114}},
{{244,247,238},{0,112,14},{6,125,21},{252,252,252},{2,126,6},{0,127,4},{29,117,31},{4,129,3}},
{{111,176,122},{242,252,244},{7,130,14},{252,251,255},{6,126,16},{15,105,18},{204,244,210},{29,109,48}},
{{7,130,14},{86,146,95},{251,246,252},{251,255,254},{3,124,18},{96,173,103},{59,133,56},{164,225,158}},
{{0,129,11},{4,128,8},{247,250,241},{240,255,245},{0,122,11},{4,132,13},{2,125,1},{8,113,31}},
{{0,129,13},{1,129,8},{27,130,39},{248,254,254},{2,124,15},{177,227,192},{236,255,244},{205,232,213}},
{{0,129,13},{0,129,13},{7,126,8},{255,255,253},{9,125,16},{5,124,6},{19,116,37},{20,99,34}},
{{0,129,13},{0,129,13},{0,129,10},{255,255,255},{2,126,6},{7,124,10},{16,108,23},{5,118,12}},
{{0,129,13},{0,129,13},{0,130,8},{45,131,60},{238,255,244},{2,123,17},{11,124,18},{27,101,24}},
{{1,128,13},{0,129,13},{0,129,13},{0,129,11},{255,255,253},{6,127,14},{4,128,8},{5,113,2}},
{{1,128,13},{0,129,13},{0,129,13},{0,130,8},{5,127,8},{255,255,253},{1,123,2},{7,127,4}},
{{237,255,239},{1,128,13},{0,129,13},{0,129,13},{0,130,8},{5,127,8},{255,255,253},{5,128,14}},
{{255,255,255},{59,123,63},{1,128,11},{0,129,13},{0,129,13},{0,129,13},{5,125,17},{249,249,247}},
{{252,252,252},{255,255,253},{208,244,198},{1,128,13},{0,129,13},{0,129,13},{0,129,13},{1,128,11}},
{{255,255,255},{255,255,255},{252,252,252},{247,251,250},{19,119,23},{0,129,13},{0,129,13},{2,125,11}},
{{255,255,255},{255,255,255},{255,255,255},{255,251,250},{0,129,13},{0,129,13},{0,129,13},{0,129,11}},
{{255,255,255},{255,255,255},{252,252,252},{95,159,98},{0,129,11},{0,129,13},{0,129,13},{10,123,17}},
{{255,255,255},{255,255,255},{252,252,252},{0,129,11},{0,129,13},{0,129,13},{4,127,13},{253,251,255}},
{{255,255,255},{254,254,254},{247,251,250},{0,129,11},{0,129,13},{0,129,13},{10,120,8},{240,252,248}},
{{255,255,255},{252,252,252},{240,255,229},{0,129,11},{0,129,13},{0,129,13},{29,132,51},{247,249,248}},
{{255,255,255},{255,255,253},{221,255,223},{0,129,13},{0,129,13},{0,129,13},{95,168,115},{248,248,248}},
{{255,254,255},{249,249,249},{241,251,252},{251,253,252},{217,246,216},{5,119,8},{29,132,53},{248,248,248}},
{{227,255,231},{15,123,21},{3,126,9},{4,118,7},{3,131,8},{34,114,45},{244,254,255},{251,253,252}},
{{1,130,14},{0,129,13},{0,129,13},{0,129,13},{0,129,13},{0,128,5},{7,125,15},{251,249,252}},
{{0,129,13},{0,129,13},{0,129,13},{0,129,13},{0,129,13},{0,129,13},{0,129,13},{1,119,7}},
{{0,129,13},{0,129,13},{0,129,13},{1,131,9},{0,128,17},{0,129,13},{0,129,13},{5,125,17}},
{{0,129,13},{4,128,8},{239,255,243},{250,252,249},{236,254,238},{0,129,13},{0,129,13},{0,129,13}},
{{12,128,17},{252,241,247},{251,253,252},{255,255,255},{255,255,255},{240,255,236},{0,129,13},{0,129,13}},
{{2,126,6},{24,101,31},{252,252,250},{255,255,255},{255,255,255},{253,253,253},{255,255,255},{5,129,19}},
{{4,117,11},{12,106,20},{51,104,58},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{254,254,254}},
{{249,249,249},{253,251,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,253}},
{{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{253,249,248}},
{{255,255,255},{255,255,255},{248,253,247},{112,141,111},{255,255,255},{255,255,255},{252,252,250},{238,254,241}},
{{237,255,241},{10,116,6},{2,126,6},{249,248,253},{255,255,255},{254,254,252},{255,251,250},{0,130,6}},
{{3,128,11},{3,126,12},{8,122,24},{247,252,248},{255,255,255},{254,254,254},{249,254,248},{114,167,113}},
{{1,128,13},{0,129,13},{0,129,13},{0,129,13},{0,129,13},{0,129,13},{1,127,19},{1,130,14}}
};