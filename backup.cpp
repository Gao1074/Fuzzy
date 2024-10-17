#include <algorithm>
#include "fuzzylogic.h"

/////////////////////////////////////////////////////////////////

//Initialise Fuzzy Rules



//#include <iostream>
//#include <fstream>
//#include <windows.h>
//#include <nlohmann/json.hpp>
//#include <string>
//short fuzzy_rules[25];
//typedef struct {
//    float a,b,c,d;
//}trap_parameter;
//trap_parameter trap_parameters[2][5];
//float A,B,C,D;
//float output_power_Value[9];
//void loadData(){
//    char cwd[MAX_PATH];
//    GetCurrentDirectory(MAX_PATH, cwd);
//    cout << "Current working directory: " << cwd << endl;
//    ifstream inputFile("data.json");
//
//    cout << !inputFile.is_open()<< endl;
//
//    nlohmann::json jsonData;
//    inputFile >> jsonData;
//    auto json_F_v =  jsonData["fuzzy"];
//    for (size_t i = 0; i < 25 ; i++) {
//
//        fuzzy_rules[i] = stoi(json_F_v[i].get<string>());
//
//    }
//    trap_parameters[INPUT_X][in_nl].a = stof(jsonData["input_X"]["NL"][0].get<string>());
//    trap_parameters[INPUT_X][in_nl].b = stof(jsonData["input_X"]["NL"][1].get<string>());
//    trap_parameters[INPUT_X][in_nl].c = stof(jsonData["input_X"]["NL"][2].get<string>());
//    trap_parameters[INPUT_X][in_nl].d = stof(jsonData["input_X"]["NL"][3].get<string>());
//
//    trap_parameters[INPUT_X][in_ns].a = stof(jsonData["input_X"]["NS"][0].get<string>());
//    trap_parameters[INPUT_X][in_ns].b = stof(jsonData["input_X"]["NS"][1].get<string>());
//    trap_parameters[INPUT_X][in_ns].c = stof(jsonData["input_X"]["NS"][2].get<string>());
//    trap_parameters[INPUT_X][in_ns].d = stof(jsonData["input_X"]["NS"][3].get<string>());
//
//
//    trap_parameters[INPUT_X][in_ze].a = stof(jsonData["input_X"]["ZE"][0].get<string>());
//    trap_parameters[INPUT_X][in_ze].b = stof(jsonData["input_X"]["ZE"][1].get<string>());
//    trap_parameters[INPUT_X][in_ze].c = stof(jsonData["input_X"]["ZE"][2].get<string>());
//    trap_parameters[INPUT_X][in_ze].d = stof(jsonData["input_X"]["ZE"][3].get<string>());
//
//    trap_parameters[INPUT_X][in_ps].a = stof(jsonData["input_X"]["PS"][0].get<string>());
//    trap_parameters[INPUT_X][in_ps].b = stof(jsonData["input_X"]["PS"][1].get<string>());
//    trap_parameters[INPUT_X][in_ps].c = stof(jsonData["input_X"]["PS"][2].get<string>());
//    trap_parameters[INPUT_X][in_ps].d = stof(jsonData["input_X"]["PS"][3].get<string>());
//
//    trap_parameters[INPUT_X][in_pl].a = stof(jsonData["input_X"]["PL"][0].get<string>());
//    trap_parameters[INPUT_X][in_pl].b = stof(jsonData["input_X"]["PL"][1].get<string>());
//    trap_parameters[INPUT_X][in_pl].c = stof(jsonData["input_X"]["PL"][2].get<string>());
//    trap_parameters[INPUT_X][in_pl].d = stof(jsonData["input_X"]["PL"][3].get<string>());
//
//
//
//
//    trap_parameters[INPUT_Y][in_nl].a = stof(jsonData["input_Y"]["NL"][0].get<string>());
//    trap_parameters[INPUT_Y][in_nl].b = stof(jsonData["input_Y"]["NL"][1].get<string>());
//    trap_parameters[INPUT_Y][in_nl].c = stof(jsonData["input_Y"]["NL"][2].get<string>());
//    trap_parameters[INPUT_Y][in_nl].d = stof(jsonData["input_Y"]["NL"][3].get<string>());
//
//    trap_parameters[INPUT_Y][in_ns].a = stof(jsonData["input_Y"]["NS"][0].get<string>());
//    trap_parameters[INPUT_Y][in_ns].b = stof(jsonData["input_Y"]["NS"][1].get<string>());
//    trap_parameters[INPUT_Y][in_ns].c = stof(jsonData["input_Y"]["NS"][2].get<string>());
//    trap_parameters[INPUT_Y][in_ns].d = stof(jsonData["input_Y"]["NS"][3].get<string>());
//
//
//    trap_parameters[INPUT_Y][in_ze].a = stof(jsonData["input_Y"]["ZE"][0].get<string>());
//    trap_parameters[INPUT_Y][in_ze].b = stof(jsonData["input_Y"]["ZE"][1].get<string>());
//    trap_parameters[INPUT_Y][in_ze].c = stof(jsonData["input_Y"]["ZE"][2].get<string>());
//    trap_parameters[INPUT_Y][in_ze].d = stof(jsonData["input_Y"]["ZE"][3].get<string>());
//
//    trap_parameters[INPUT_Y][in_ps].a = stof(jsonData["input_Y"]["PS"][0].get<string>());
//    trap_parameters[INPUT_Y][in_ps].b = stof(jsonData["input_Y"]["PS"][1].get<string>());
//    trap_parameters[INPUT_Y][in_ps].c = stof(jsonData["input_Y"]["PS"][2].get<string>());
//    trap_parameters[INPUT_Y][in_ps].d = stof(jsonData["input_Y"]["PS"][3].get<string>());
//
//    trap_parameters[INPUT_Y][in_pl].a = stof(jsonData["input_Y"]["PL"][0].get<string>());
//    trap_parameters[INPUT_Y][in_pl].b = stof(jsonData["input_Y"]["PL"][1].get<string>());
//    trap_parameters[INPUT_Y][in_pl].c = stof(jsonData["input_Y"]["PL"][2].get<string>());
//    trap_parameters[INPUT_Y][in_pl].d = stof(jsonData["input_Y"]["PL"][3].get<string>());
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            cout<<trap_parameters[i][j].a <<" ";
//            cout<<trap_parameters[i][j].b <<" ";
//            cout<<trap_parameters[i][j].c <<" ";
//            cout<<trap_parameters[i][j].d<<endl;
//
//        }
//    }
//
//    A = stof(jsonData["parameters"][0].get<string>());
//    B = stof(jsonData["parameters"][1].get<string>());
//    C = stof(jsonData["parameters"][2].get<string>());
//    D = stof(jsonData["parameters"][3].get<string>());
//    cout << A <<endl;
//    cout << B<<endl;
//    cout << C<<endl;
//    cout << D<<endl;
//    for (int i = 0; i < 9; ++i) {
//        output_power_Value[i] = stof(jsonData["output_Strength"][i].get<string>());
//        cout << output_power_Value[i]<<endl;
//    }
//
//}




//rule -------------------------------------
void initFuzzyRules(fuzzy_system_rec *fl) {

    const int no_of_XY_rules = 25;
    for (int i = 0;i < no_of_XY_rules;i++) {
        fl->rules[i].inp_index[0] = INPUT_X;
        fl->rules[i].inp_index[1] = INPUT_Y;
    }
//    fl->rules[0].inp_fuzzy_set[0] = in_nl;
//    fl->rules[0].inp_fuzzy_set[1] = in_nl;
//    for (int i = 0; i < 25; ++i) {
//        fl->rules[i].out_fuzzy_set = fuzzy_rules[i];
//    }


    fl->rules[0].inp_fuzzy_set[0] = in_nl;
    fl->rules[0].inp_fuzzy_set[1] = in_pl;
    fl->rules[1].inp_fuzzy_set[0] = in_nl;
    fl->rules[1].inp_fuzzy_set[1] = in_ps;
    fl->rules[2].inp_fuzzy_set[0] = in_nl;
    fl->rules[2].inp_fuzzy_set[1] = in_ze;
    fl->rules[3].inp_fuzzy_set[0] = in_nl;
    fl->rules[3].inp_fuzzy_set[1] = in_ns;
    fl->rules[4].inp_fuzzy_set[0] = in_nl;
    fl->rules[4].inp_fuzzy_set[1] = in_nl;
    fl->rules[5].inp_fuzzy_set[0] = in_ns;
    fl->rules[5].inp_fuzzy_set[1] = in_pl;
    fl->rules[6].inp_fuzzy_set[0] = in_ns;
    fl->rules[6].inp_fuzzy_set[1] = in_ps;
    fl->rules[7].inp_fuzzy_set[0] = in_ns;
    fl->rules[7].inp_fuzzy_set[1] = in_ze;
    fl->rules[8].inp_fuzzy_set[0] = in_ns;
    fl->rules[8].inp_fuzzy_set[1] = in_ns;
    fl->rules[9].inp_fuzzy_set[0] = in_ns;
    fl->rules[9].inp_fuzzy_set[1] = in_nl;
    fl->rules[10].inp_fuzzy_set[0] = in_ze;
    fl->rules[10].inp_fuzzy_set[1] = in_pl;
    fl->rules[11].inp_fuzzy_set[0] = in_ze;
    fl->rules[11].inp_fuzzy_set[1] = in_ps;
    fl->rules[12].inp_fuzzy_set[0] = in_ze;
    fl->rules[12].inp_fuzzy_set[1] = in_ze;
    fl->rules[13].inp_fuzzy_set[0] = in_ze;
    fl->rules[13].inp_fuzzy_set[1] = in_ns;
    fl->rules[14].inp_fuzzy_set[0] = in_ze;
    fl->rules[14].inp_fuzzy_set[1] = in_nl;
    fl->rules[15].inp_fuzzy_set[0] = in_ps;
    fl->rules[15].inp_fuzzy_set[1] = in_pl;
    fl->rules[16].inp_fuzzy_set[0] = in_ps;
    fl->rules[16].inp_fuzzy_set[1] = in_ps;
    fl->rules[17].inp_fuzzy_set[0] = in_ps;
    fl->rules[17].inp_fuzzy_set[1] = in_ze;
    fl->rules[18].inp_fuzzy_set[0] = in_ps;
    fl->rules[18].inp_fuzzy_set[1] = in_ns;
    fl->rules[19].inp_fuzzy_set[0] = in_ps;
    fl->rules[19].inp_fuzzy_set[1] = in_nl;
    fl->rules[20].inp_fuzzy_set[0] = in_pl;
    fl->rules[20].inp_fuzzy_set[1] = in_pl;
    fl->rules[21].inp_fuzzy_set[0] = in_pl;
    fl->rules[21].inp_fuzzy_set[1] = in_ps;
    fl->rules[22].inp_fuzzy_set[0] = in_pl;
    fl->rules[22].inp_fuzzy_set[1] = in_ze;
    fl->rules[23].inp_fuzzy_set[0] = in_pl;
    fl->rules[23].inp_fuzzy_set[1] = in_ns;
    fl->rules[24].inp_fuzzy_set[0] = in_pl;
    fl->rules[24].inp_fuzzy_set[1] = in_nl;

    fl->rules[0].out_fuzzy_set = out_ns;
    fl->rules[1].out_fuzzy_set = out_ze;
    fl->rules[2].out_fuzzy_set = out_nm;
    fl->rules[3].out_fuzzy_set = out_ze;
    fl->rules[4].out_fuzzy_set = out_nl;
    fl->rules[5].out_fuzzy_set = out_ze;
    fl->rules[6].out_fuzzy_set = out_ns;
    fl->rules[7].out_fuzzy_set = out_ze;
    fl->rules[8].out_fuzzy_set = out_nm;
    fl->rules[9].out_fuzzy_set = out_ze;
    fl->rules[10].out_fuzzy_set = out_ps;
    fl->rules[11].out_fuzzy_set = out_ze;
    fl->rules[12].out_fuzzy_set = out_ze;
    fl->rules[13].out_fuzzy_set = out_ze;
    fl->rules[14].out_fuzzy_set = out_ns;
    fl->rules[15].out_fuzzy_set = out_ze;
    fl->rules[16].out_fuzzy_set = out_pm;
    fl->rules[17].out_fuzzy_set = out_ze;
    fl->rules[18].out_fuzzy_set = out_ps;
    fl->rules[19].out_fuzzy_set = out_ze;
    fl->rules[20].out_fuzzy_set = out_pl;
    fl->rules[21].out_fuzzy_set = out_ze;
    fl->rules[22].out_fuzzy_set = out_pm;
    fl->rules[23].out_fuzzy_set = out_ze;
    fl->rules[24].out_fuzzy_set = out_ps;







    for (int i = 0; i < no_of_XY_rules; ++i) {
//        fl->rules[i].inp_fuzzy_set[0] = (i / 5);
//        fl->rules[i].inp_fuzzy_set[1] = (i % 5) ;
//
//        fl->rules[i].out_fuzzy_set = 4 - (i % 5) + (i / 5);
        cout <<"X(angle): "<<fl->rules[i].inp_fuzzy_set[0]<<"  Y(x): "<<fl->rules[i].inp_fuzzy_set[1]<<"   out: "<<fl-> rules[i].out_fuzzy_set<<endl;
    }

}

//隶属函数---------------------------------------------------------------
void initMembershipFunctions(fuzzy_system_rec *fl) {
//    fl->inp_mem_fns[INPUT_X][in_nl] = convert_degree_init_trap (trap_parameters[INPUT_X][in_nl].a,trap_parameters[INPUT_X][in_nl].b,trap_parameters[INPUT_X][in_nl].c,trap_parameters[INPUT_X][in_nl].d,left_trapezoid);
//
//    fl->inp_mem_fns[INPUT_X][in_ns] = convert_degree_init_trap (trap_parameters[INPUT_X][in_ns].a,trap_parameters[INPUT_X][in_ns].b,trap_parameters[INPUT_X][in_ns].c,trap_parameters[INPUT_X][in_ns].d,regular_trapezoid);
//
//    fl->inp_mem_fns[INPUT_X][in_ze] = convert_degree_init_trap (trap_parameters[INPUT_X][in_ze].a,trap_parameters[INPUT_X][in_ze].b,trap_parameters[INPUT_X][in_ze].c,trap_parameters[INPUT_X][in_ze].d,regular_trapezoid);
//
//    fl->inp_mem_fns[INPUT_X][in_ps] = convert_degree_init_trap (trap_parameters[INPUT_X][in_ps].a,trap_parameters[INPUT_X][in_ps].b,trap_parameters[INPUT_X][in_ps].c,trap_parameters[INPUT_X][in_ps].d,regular_trapezoid);
//
//    fl->inp_mem_fns[INPUT_X][in_pl] = convert_degree_init_trap (trap_parameters[INPUT_X][in_pl].a,trap_parameters[INPUT_X][in_pl].b,trap_parameters[INPUT_X][in_pl].c,trap_parameters[INPUT_X][in_pl].d,right_trapezoid);
//
//    //Y
//    fl->inp_mem_fns[INPUT_Y][in_nl] = convert_degree_init_trap (trap_parameters[INPUT_Y][in_nl].a,trap_parameters[INPUT_Y][in_nl].b,trap_parameters[INPUT_Y][in_nl].c,trap_parameters[INPUT_Y][in_nl].d,left_trapezoid);
//
//    fl->inp_mem_fns[INPUT_Y][in_ns] = convert_degree_init_trap (trap_parameters[INPUT_Y][in_ns].a,trap_parameters[INPUT_Y][in_ns].b,trap_parameters[INPUT_Y][in_ns].c,trap_parameters[INPUT_Y][in_ns].d,regular_trapezoid);
//
//    fl->inp_mem_fns[INPUT_Y][in_ze] = convert_degree_init_trap (trap_parameters[INPUT_Y][in_ze].a,trap_parameters[INPUT_Y][in_ze].b,trap_parameters[INPUT_Y][in_ze].c,trap_parameters[INPUT_Y][in_ze].d,regular_trapezoid);
//
//    fl->inp_mem_fns[INPUT_Y][in_ps] = convert_degree_init_trap (trap_parameters[INPUT_Y][in_ps].a,trap_parameters[INPUT_Y][in_ps].b,trap_parameters[INPUT_Y][in_ps].c,trap_parameters[INPUT_Y][in_ps].d,regular_trapezoid);
//
//    fl->inp_mem_fns[INPUT_Y][in_pl] = convert_degree_init_trap (trap_parameters[INPUT_Y][in_pl].a,trap_parameters[INPUT_Y][in_pl].b,trap_parameters[INPUT_Y][in_pl].c,trap_parameters[INPUT_Y][in_pl].d,right_trapezoid);
//
    fl->inp_mem_fns[0][in_nl] = init_trapz (-0.39, -0.23, 0, 0, left_trapezoid);
    fl->inp_mem_fns[0][in_ns] = init_trapz (-0.39, -0.23, -0.19, -0.02, regular_trapezoid);
    fl->inp_mem_fns[0][in_ze] = init_trapz (-0.19, -0.02, 0.02, 0.19, regular_trapezoid);
    fl->inp_mem_fns[0][in_ps] = init_trapz (0.02, 0.19, 0.22, 0.39, regular_trapezoid);
    fl->inp_mem_fns[0][in_pl] = init_trapz (0.22, 0.39, 0, 0, right_trapezoid);
    /* The theta membership functions */
    //enter the appropriate membership function initialisations here
    fl->inp_mem_fns[1][in_nl] = init_trapz (-2.29, -1.33, 0, 0, left_trapezoid);
    fl->inp_mem_fns[1][in_ns] = init_trapz (-2.29, -1.32, -1.09, -0.12, regular_trapezoid);
    fl->inp_mem_fns[1][in_ze] = init_trapz (-1.09, -0.12, 0.12, 1.09, regular_trapezoid);
    fl->inp_mem_fns[1][in_ps] = init_trapz (0.13, 1.09, 1.32, 2.29, regular_trapezoid);
    fl->inp_mem_fns[1][in_pl] = init_trapz (1.31, 2.29, 0, 0, right_trapezoid);

    //2 inputs
    //X
//    fl->inp_mem_fns[INPUT_X][in_nl] = convert_degree_init_trap (0, 0, -20, -15, left_trapezoid);
//
//    fl->inp_mem_fns[INPUT_X][in_ns] = convert_degree_init_trap (-20, -15, -10, -1, regular_trapezoid);
//
//    fl->inp_mem_fns[INPUT_X][in_ze] = convert_degree_init_trap (-10, -1, 1, 10, regular_trapezoid);
//
//    fl->inp_mem_fns[INPUT_X][in_ps] = convert_degree_init_trap (1, 10, 15, 20, regular_trapezoid);
//
//    fl->inp_mem_fns[INPUT_X][in_pl] = convert_degree_init_trap (15, 20, 0, 0, right_trapezoid);


//    fl->inp_mem_fns[INPUT_X][in_nl] = convert_degree_init_trap (0,0,-45,-30,left_trapezoid);
//
//    fl->inp_mem_fns[INPUT_X][in_ns] = convert_degree_init_trap (-45,-30,-15,0,regular_trapezoid);
//
//    fl->inp_mem_fns[INPUT_X][in_ze] = convert_degree_init_trap (-5,0,0,5,regular_trapezoid);
//
//    fl->inp_mem_fns[INPUT_X][in_ps] = convert_degree_init_trap (0,15,30,45,regular_trapezoid);
//
//    fl->inp_mem_fns[INPUT_X][in_pl] = convert_degree_init_trap (30,45,0,0,right_trapezoid);

    //Y
//    fl->inp_mem_fns[INPUT_Y][in_nl] = init_trapz (0,0,-1.5,-1,left_trapezoid);
//
//    fl->inp_mem_fns[INPUT_Y][in_ns] = init_trapz (-1.5,-1,-0.6,-0.1,regular_trapezoid);
//
//    fl->inp_mem_fns[INPUT_Y][in_ze] = init_trapz (-0.6,0,0,0.6,regular_trapezoid);
//
//    fl->inp_mem_fns[INPUT_Y][in_ps] = init_trapz (0.1,0.6,1,1.5,regular_trapezoid);
//
//    fl->inp_mem_fns[INPUT_Y][in_pl] = init_trapz (1,1.5,0,0,right_trapezoid);



   return;
}
float degree_convert(float degree){
    float x;
    x = degree * (3.14f/180);
    return x;
}
trapezoid convert_degree_init_trap(float x1,float x2,float x3,float x4, trapz_type typ){
    x1 = degree_convert(x1);
    x2 = degree_convert(x2);
    x3 = degree_convert(x3);
    x4 = degree_convert(x4);
    return init_trapz(x1,x2,x3,x4,typ);
}


void initFuzzySystem (fuzzy_system_rec *fl) {

    //loadData();

   //Note: The settings of these parameters will depend upon your fuzzy system design
   fl->no_of_inputs = 2;  /* Inputs are handled 2 at a time only */
   fl->no_of_rules = 25;
   fl->no_of_inp_regions = 5;
   fl->no_of_outputs = 7;
   //fl->no_of_outputs = 9;
//    coefficient_A = A;
//    coefficient_B = B;
//    coefficient_C = C;
//    coefficient_D = D;

   coefficient_A=20;
   coefficient_B=2;
   coefficient_C=6;
   coefficient_D=9;

	//Sample only out_nvl,out_nl,out_nm, out_ns, out_ze,out_ps, out_pm,out_pl, out_pvl

//    fl->output_values [out_nvl] = output_power_Value[out_nvl];
//    fl->output_values [out_nl] = output_power_Value[out_nl];
//    fl->output_values [out_nm] = output_power_Value[out_nm];
//    fl->output_values [out_ns] = output_power_Value[out_ns];
//    fl->output_values [out_ze] = output_power_Value[out_ze];
//    fl->output_values [out_ps] = output_power_Value[out_ps];
//    fl->output_values [out_ps] = output_power_Value[out_ps];
//    fl->output_values [out_pl] = output_power_Value[out_pl];
//    fl->output_values [out_pvl] = output_power_Value[out_pvl];

	// fl->output_values [out_nvl]=-95.0;
	// fl->output_values [out_nl] = -85.0;
//    fl->output_values [out_nvl] = -500.0;
//    fl->output_values [out_nl] = -400.0;
//    fl->output_values [out_nm] = -300.0;
//    fl->output_values [out_ns] = -200.0;
//    fl->output_values [out_ze] = 0;
//    fl->output_values [out_ps] = 200.0;
//    fl->output_values [out_pm] = 300.0;
//    fl->output_values [out_pl] = 400.0;
//    fl->output_values [out_pvl] = 500.0;
    fl->output_values[out_nl] = -430.0;
    fl->output_values[out_nm] = -430.0 + 1*860.0/6;
    fl->output_values[out_ns] = -430.0 + 2*860.0/6;
    fl->output_values[out_ze] = -430.0 + 3*860.0/6;
    fl->output_values[out_ps] = -430.0 + 4*860.0/6;
    fl->output_values[out_pm] = -430.0 + 5*860.0/6;
    fl->output_values[out_pl] = 430.0;


   fl->rules = (rule *) malloc ((size_t)(fl->no_of_rules*sizeof(rule)));
   initFuzzyRules(fl);
   initMembershipFunctions(fl);
   return;
}

//////////////////////////////////////////////////////////////////////////////

trapezoid init_trapz (float x1,float x2,float x3,float x4, trapz_type typ) {

   trapezoid trz;
   trz.a = x1;
   trz.b = x2;
   trz.c = x3;
   trz.d = x4;
   trz.tp = typ;
   switch (trz.tp) {

      case regular_trapezoid:
             trz.l_slope = 1.0/(trz.b - trz.a);
             trz.r_slope = 1.0/(trz.c - trz.d);
             break;

      case left_trapezoid: //2024, corrected version - to match variables used in the lectures - (c, d) instead of (a,b)
             trz.r_slope = 1.0/(trz.c - trz.d);
             trz.l_slope = 0.0;
             break;

      case right_trapezoid:
             trz.l_slope = 1.0/(trz.b - trz.a);
             trz.r_slope = 0.0;
             break;
   }  /* end switch  */

   return trz;
}  /* end function */

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
float trapz (float x, trapezoid trz) {
   switch (trz.tp) {

      case left_trapezoid: //2024, corrected version - to match variables used in the lectures - (c, d) instead of (a,b)
             if (x <= trz.c)
                return 1.0;
             if (x >= trz.d)
                return 0.0;
             /* c < x < d */
             return trz.r_slope * (x - trz.d);


      case right_trapezoid:
             if (x <= trz.a)
                return 0.0;
             if (x >= trz.b)
                return 1.0;
             /* a < x < b */
             return trz.l_slope * (x - trz.a);

      case regular_trapezoid:
             if ((x <= trz.a) || (x >= trz.d))
                return 0.0;
             if ((x >= trz.b) && (x <= trz.c))
                return 1.0;
             if ((x >= trz.a) && (x <= trz.b))
                return trz.l_slope * (x - trz.a);
             if ((x >= trz.c) && (x <= trz.d))
                return  trz.r_slope * (x - trz.d);

     }  /* End switch  */

   return 0.0;  /* should not get to this point */
}  /* End function */

//////////////////////////////////////////////////////////////////////////////
float min_of(float values[],int no_of_inps) {
   int i;
   float val;
   val = values [0];
   for (i = 1;i < no_of_inps;i++) {
       if (values[i] < val)
	  val = values [i];
   }
   return val;
}



//////////////////////////////////////////////////////////////////////////////
float fuzzy_system (float inputs[],fuzzy_system_rec fz) {
   int i,j;
   short variable_index,fuzzy_set;
   float sum1 = 0.0,sum2 = 0.0,weight;
   float m_values[MAX_NO_OF_INPUTS];

   for (i = 0;i < fz.no_of_rules;i++) {
      for (j = 0;j < fz.no_of_inputs;j++) {
	   variable_index = fz.rules[i].inp_index[j];
	   fuzzy_set = fz.rules[i].inp_fuzzy_set[j];
	   m_values[j] = trapz(inputs[variable_index],
	       fz.inp_mem_fns[variable_index][fuzzy_set]);
	   } /* end j  */


       weight = min_of (m_values,fz.no_of_inputs);


       sum1 += weight * fz.output_values[fz.rules[i].out_fuzzy_set];
       sum2 += weight;
   } /* end i  */



	if (fabs(sum2) < TOO_SMALL) {
      cout << "\r\nFLPRCS Error: Sum2 in fuzzy_system is 0.  Press key: " << endl;
      //~ getch();
      //~ exit(1);
      return 0.0;
   }

   return (sum1/sum2);
}  /* end fuzzy_system  */

//////////////////////////////////////////////////////////////////////////////
void free_fuzzy_rules (fuzzy_system_rec *fz) {
   if (fz->allocated){
	   free (fz->rules);
	}

   fz->allocated = false;
   return;
}

