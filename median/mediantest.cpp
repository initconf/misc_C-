//
//  mediantest.cpp
//  c++
//
//  Created by Aashish Sharma on 10/1/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "median.h" 


#if 0
int main()
{
    
    for (int i = 1000 ; i <=1500000; i+=10000)
    {
        
       
        median m(i/2, i) ;
      
    }

//    cout << endl << endl << "Run time for nth largest is: " << double(end - start)/CLOCKS_PER_SEC << " secs" << endl ;
    
    
    // random_in_range(10, 20);
    
    return 0 ;
    
}

//#endif





I: 1000 kth: 502  Time: 2.1e-05 secs
I: 11000 kth: 5502  Time: 0.000297 secs
I: 21000 kth: 10503  Time: 0.00044 secs
I: 31000 kth: 15504  Time: 0.000877 secs
I: 41000 kth: 20506  Time: 0.000799 secs
I: 51000 kth: 25503  Time: 0.001109 secs
I: 61000 kth: 30504  Time: 0.001496 secs
I: 71000 kth: 35506  Time: 0.001415 secs
I: 81000 kth: 40502  Time: 0.001458 secs
I: 91000 kth: 45503  Time: 0.002043 secs
I: 101000 kth: 50504  Time: 0.002378 secs
I: 111000 kth: 55505  Time: 0.002148 secs
I: 121000 kth: 60504  Time: 0.002573 secs
I: 131000 kth: 65501  Time: 0.002344 secs
I: 141000 kth: 70507  Time: 0.004562 secs
I: 151000 kth: 75504  Time: 0.002811 secs
I: 161000 kth: 80510  Time: 0.00273 secs
I: 171000 kth: 85503  Time: 0.003377 secs
I: 181000 kth: 90503  Time: 0.002181 secs
I: 191000 kth: 95503  Time: 0.003409 secs
I: 201000 kth: 100502  Time: 0.002486 secs
I: 211000 kth: 105504  Time: 0.004812 secs
I: 221000 kth: 110497  Time: 0.004757 secs
I: 231000 kth: 115504  Time: 0.004272 secs
I: 241000 kth: 120498  Time: 0.003422 secs
I: 251000 kth: 125503  Time: 0.003887 secs
I: 261000 kth: 130505  Time: 0.004341 secs
I: 271000 kth: 135508  Time: 0.003955 secs
I: 281000 kth: 140503  Time: 0.005708 secs
I: 291000 kth: 145504  Time: 0.008531 secs
I: 301000 kth: 150505  Time: 0.004582 secs
I: 311000 kth: 155508  Time: 0.007203 secs
I: 321000 kth: 160502  Time: 0.005635 secs
I: 331000 kth: 165503  Time: 0.005953 secs
I: 341000 kth: 170506  Time: 0.006945 secs
I: 351000 kth: 175507  Time: 0.005799 secs
I: 361000 kth: 180506  Time: 0.004813 secs
I: 371000 kth: 185504  Time: 0.007256 secs
I: 381000 kth: 190500  Time: 0.006909 secs
I: 391000 kth: 195504  Time: 0.007027 secs
I: 401000 kth: 200502  Time: 0.006455 secs
I: 411000 kth: 205504  Time: 0.006408 secs
I: 421000 kth: 210470  Time: 0.008348 secs
I: 431000 kth: 215504  Time: 0.007022 secs
I: 441000 kth: 220507  Time: 0.008176 secs
I: 451000 kth: 225400  Time: 0.009644 secs
I: 461000 kth: 230503  Time: 0.011412 secs
I: 471000 kth: 235505  Time: 0.00926 secs
I: 481000 kth: 240504  Time: 0.011238 secs
I: 491000 kth: 245502  Time: 0.01017 secs
I: 501000 kth: 250502  Time: 0.010988 secs
I: 511000 kth: 255505  Time: 0.009519 secs
I: 521000 kth: 260500  Time: 0.008364 secs
I: 531000 kth: 265504  Time: 0.012967 secs
I: 541000 kth: 270502  Time: 0.009252 secs
I: 551000 kth: 275504  Time: 0.005307 secs
I: 561000 kth: 280504  Time: 0.010732 secs
I: 571000 kth: 285504  Time: 0.011546 secs
I: 581000 kth: 290503  Time: 0.013411 secs
I: 591000 kth: 295503  Time: 0.0084 secs
I: 601000 kth: 300509  Time: 0.020308 secs
I: 611000 kth: 305507  Time: 0.013827 secs
I: 621000 kth: 310510  Time: 0.012008 secs
I: 631000 kth: 315509  Time: 0.015504 secs
I: 641000 kth: 320508  Time: 0.014807 secs
I: 651000 kth: 325506  Time: 0.007153 secs
I: 661000 kth: 330511  Time: 0.01342 secs
I: 671000 kth: 335502  Time: 0.014741 secs
I: 681000 kth: 340506  Time: 0.016512 secs
I: 691000 kth: 345502  Time: 0.013101 secs
I: 701000 kth: 350506  Time: 0.013057 secs
I: 711000 kth: 355505  Time: 0.015475 secs
I: 721000 kth: 360503  Time: 0.01849 secs
I: 731000 kth: 365502  Time: 0.016764 secs
I: 741000 kth: 370504  Time: 0.019056 secs
I: 751000 kth: 375508  Time: 0.020693 secs
I: 761000 kth: 380427  Time: 0.016543 secs
I: 771000 kth: 385506  Time: 0.01341 secs
I: 781000 kth: 390504  Time: 0.016314 secs
I: 791000 kth: 395502  Time: 0.014861 secs
I: 801000 kth: 400509  Time: 0.022004 secs
I: 811000 kth: 405504  Time: 0.012564 secs
I: 821000 kth: 410510  Time: 0.014752 secs
I: 831000 kth: 415506  Time: 0.009675 secs
I: 841000 kth: 420508  Time: 0.016516 secs
I: 851000 kth: 425499  Time: 0.009518 secs
I: 861000 kth: 430499  Time: 0.008857 secs
I: 871000 kth: 435503  Time: 0.022801 secs
I: 881000 kth: 440502  Time: 0.021424 secs
I: 891000 kth: 445380  Time: 0.013547 secs
I: 901000 kth: 450503  Time: 0.013136 secs
I: 911000 kth: 455506  Time: 0.017723 secs
I: 921000 kth: 460504  Time: 0.012085 secs
I: 931000 kth: 465506  Time: 0.014999 secs
I: 941000 kth: 470506  Time: 0.018811 secs
I: 951000 kth: 475506  Time: 0.02394 secs
I: 961000 kth: 480398  Time: 0.026316 secs
I: 971000 kth: 485500  Time: 0.011232 secs
I: 981000 kth: 490501  Time: 0.013682 secs
I: 991000 kth: 495508  Time: 0.016566 secs
I: 1001000 kth: 500503  Time: 0.015991 secs
I: 1011000 kth: 505509  Time: 0.028362 secs
I: 1021000 kth: 510504  Time: 0.013322 secs
I: 1031000 kth: 515506  Time: 0.017332 secs
I: 1041000 kth: 520508  Time: 0.022549 secs
I: 1051000 kth: 525505  Time: 0.022889 secs
I: 1061000 kth: 530504  Time: 0.017792 secs
I: 1071000 kth: 535505  Time: 0.01279 secs
I: 1081000 kth: 540495  Time: 0.015932 secs
I: 1091000 kth: 545504  Time: 0.016789 secs
I: 1101000 kth: 550505  Time: 0.019477 secs
I: 1111000 kth: 555506  Time: 0.022085 secs
I: 1121000 kth: 560506  Time: 0.02233 secs
I: 1131000 kth: 565506  Time: 0.023303 secs
I: 1141000 kth: 570504  Time: 0.025527 secs
I: 1151000 kth: 575506  Time: 0.022321 secs
I: 1161000 kth: 580479  Time: 0.026076 secs
I: 1171000 kth: 585499  Time: 0.018154 secs
I: 1181000 kth: 590505  Time: 0.026102 secs
I: 1191000 kth: 595506  Time: 0.031673 secs
I: 1201000 kth: 600505  Time: 0.018125 secs
I: 1211000 kth: 605505  Time: 0.020816 secs
I: 1221000 kth: 610505  Time: 0.016265 secs
I: 1231000 kth: 615510  Time: 0.022943 secs
I: 1241000 kth: 620505  Time: 0.030764 secs
I: 1251000 kth: 625505  Time: 0.028017 secs
I: 1261000 kth: 630507  Time: 0.026026 secs
I: 1271000 kth: 635502  Time: 0.025612 secs
I: 1281000 kth: 640503  Time: 0.02012 secs
I: 1291000 kth: 645503  Time: 0.029527 secs
I: 1301000 kth: 650508  Time: 0.019642 secs
I: 1311000 kth: 655451  Time: 0.019654 secs
I: 1321000 kth: 660504  Time: 0.023926 secs
I: 1331000 kth: 665286  Time: 0.018607 secs
I: 1341000 kth: 670506  Time: 0.036808 secs
I: 1351000 kth: 675508  Time: 0.019215 secs
I: 1361000 kth: 680504  Time: 0.034257 secs
I: 1371000 kth: 685507  Time: 0.028541 secs
I: 1381000 kth: 690505  Time: 0.038981 secs
I: 1391000 kth: 695509  Time: 0.029828 secs
I: 1401000 kth: 700505  Time: 0.016368 secs
I: 1411000 kth: 705513  Time: 0.020229 secs
I: 1421000 kth: 710505  Time: 0.03574 secs
I: 1431000 kth: 715508  Time: 0.035575 secs
I: 1441000 kth: 720505  Time: 0.035046 secs
I: 1451000 kth: 725505  Time: 0.030465 secs
I: 1461000 kth: 730504  Time: 0.023994 secs
I: 1471000 kth: 735507  Time: 0.029563 secs
I: 1481000 kth: 740508  Time: 0.021027 secs
I: 1491000 kth: 745499  Time: 0.023126 secs
Program ended with exit code: 0

#endif
