#include <algorithm>
#include "fuzzylogic.h"

/////////////////////////////////////////////////////////////////


//rule -------------------------------------
void initFuzzyRules(fuzzy_system_rec *fl) {

    const int no_of_XY_rules = 25;
    for (int i = 0;i < no_of_XY_rules;i++) {
        fl->rules[i].inp_index[0] = INPUT_X;
        fl->rules[i].inp_index[1] = INPUT_Y;
    }

    fl->rules[0].inp_fuzzy_set[INPUT_X] = in_nl;
    fl->rules[0].inp_fuzzy_set[INPUT_Y] = in_pl;
    fl->rules[0].out_fuzzy_set = out_nm;

    fl->rules[1].inp_fuzzy_set[INPUT_X] = in_nl;
    fl->rules[1].inp_fuzzy_set[INPUT_Y] = in_ps;
    fl->rules[1].out_fuzzy_set = out_ns;

    fl->rules[2].inp_fuzzy_set[INPUT_X] = in_nl;
    fl->rules[2].inp_fuzzy_set[INPUT_Y] = in_ze;
    fl->rules[2].out_fuzzy_set = out_nl;

    fl->rules[3].inp_fuzzy_set[INPUT_X] = in_nl;
    fl->rules[3].inp_fuzzy_set[INPUT_Y] = in_ns;
    fl->rules[3].out_fuzzy_set = out_ns;

    fl->rules[4].inp_fuzzy_set[INPUT_X] = in_nl;
    fl->rules[4].inp_fuzzy_set[INPUT_Y] = in_nl;
    fl->rules[4].out_fuzzy_set = out_nvl;

    fl->rules[5].inp_fuzzy_set[INPUT_X] = in_ns;
    fl->rules[5].inp_fuzzy_set[INPUT_Y] = in_pl;
    fl->rules[5].out_fuzzy_set = out_ns;

    fl->rules[6].inp_fuzzy_set[INPUT_X] = in_ns;
    fl->rules[6].inp_fuzzy_set[INPUT_Y] = in_ps;
    fl->rules[6].out_fuzzy_set = out_nm;

    fl->rules[7].inp_fuzzy_set[INPUT_X] = in_ns;
    fl->rules[7].inp_fuzzy_set[INPUT_Y] = in_ze;
    fl->rules[7].out_fuzzy_set = out_ns;

    fl->rules[8].inp_fuzzy_set[INPUT_X] = in_ns;
    fl->rules[8].inp_fuzzy_set[INPUT_Y] = in_ns;
    fl->rules[8].out_fuzzy_set = out_nl;

    fl->rules[9].inp_fuzzy_set[INPUT_X] = in_ns;
    fl->rules[9].inp_fuzzy_set[INPUT_Y] = in_nl;
    fl->rules[9].out_fuzzy_set = out_ns;

    fl->rules[10].inp_fuzzy_set[INPUT_X] = in_ze;
    fl->rules[10].inp_fuzzy_set[INPUT_Y] = in_pl;
    fl->rules[10].out_fuzzy_set = out_nm;

    fl->rules[11].inp_fuzzy_set[INPUT_X] = in_ze;
    fl->rules[11].inp_fuzzy_set[INPUT_Y] = in_ps;
    fl->rules[11].out_fuzzy_set = out_ns;

    fl->rules[12].inp_fuzzy_set[INPUT_X] = in_ze;
    fl->rules[12].inp_fuzzy_set[INPUT_Y] = in_ze;
    fl->rules[12].out_fuzzy_set = out_ze;

    fl->rules[13].inp_fuzzy_set[INPUT_X] = in_ze;
    fl->rules[13].inp_fuzzy_set[INPUT_Y] = in_ns;
    fl->rules[13].out_fuzzy_set = out_ns;

    fl->rules[14].inp_fuzzy_set[INPUT_X] = in_ze;
    fl->rules[14].inp_fuzzy_set[INPUT_Y] = in_nl;
    fl->rules[14].out_fuzzy_set = out_pm;

    fl->rules[15].inp_fuzzy_set[INPUT_X] = in_ps;
    fl->rules[15].inp_fuzzy_set[INPUT_Y] = in_pl;
    fl->rules[15].out_fuzzy_set = out_ps;

    fl->rules[16].inp_fuzzy_set[INPUT_X] = in_ps;
    fl->rules[16].inp_fuzzy_set[INPUT_Y] = in_ps;
    fl->rules[16].out_fuzzy_set = out_pl;

    fl->rules[17].inp_fuzzy_set[INPUT_X] = in_ps;
    fl->rules[17].inp_fuzzy_set[INPUT_Y] = in_ze;
    fl->rules[17].out_fuzzy_set = out_ps;

    fl->rules[18].inp_fuzzy_set[INPUT_X] = in_ps;
    fl->rules[18].inp_fuzzy_set[INPUT_Y] = in_ns;
    fl->rules[18].out_fuzzy_set = out_pm;

    fl->rules[19].inp_fuzzy_set[INPUT_X] = in_ps;
    fl->rules[19].inp_fuzzy_set[INPUT_Y] = in_nl;
    fl->rules[19].out_fuzzy_set = out_ps;

    fl->rules[20].inp_fuzzy_set[INPUT_X] = in_pl;
    fl->rules[20].inp_fuzzy_set[INPUT_Y] = in_pl;
    fl->rules[20].out_fuzzy_set = out_pvl;

    fl->rules[21].inp_fuzzy_set[INPUT_X] = in_pl;
    fl->rules[21].inp_fuzzy_set[INPUT_Y] = in_ps;
    fl->rules[21].out_fuzzy_set = out_ps;

    fl->rules[22].inp_fuzzy_set[INPUT_X] = in_pl;
    fl->rules[22].inp_fuzzy_set[INPUT_Y] = in_ze;
    fl->rules[22].out_fuzzy_set = out_pl;

    fl->rules[23].inp_fuzzy_set[INPUT_X] = in_pl;
    fl->rules[23].inp_fuzzy_set[INPUT_Y] = in_ns;
    fl->rules[23].out_fuzzy_set = out_ps;

    fl->rules[24].inp_fuzzy_set[INPUT_X] = in_pl;
    fl->rules[24].inp_fuzzy_set[INPUT_Y] = in_nl;
    fl->rules[24].out_fuzzy_set = out_pm;


    for (int i = 0; i < no_of_XY_rules; ++i) {
        cout <<"X(angle): "<<fl->rules[i].inp_fuzzy_set[0]<<"  Y(x): "<<fl->rules[i].inp_fuzzy_set[1]<<"   out: "<<fl-> rules[i].out_fuzzy_set<<endl;
    }

}
/*
    X(angle): NL  Y(x): PL   out: NM
    X(angle): NL  Y(x): PS   out: NS
    X(angle): NL  Y(x): ZE   out: NL
    X(angle): NL  Y(x): NS   out: NS
    X(angle): NL  Y(x): NL   out: NVL
    X(angle): NS  Y(x): PL   out: NS
    X(angle): NS  Y(x): PS   out: NM
    X(angle): NS  Y(x): ZE   out: NS
    X(angle): NS  Y(x): NS   out: NL
    X(angle): NS  Y(x): NL   out: NS
    X(angle): ZE  Y(x): PL   out: NM
    X(angle): ZE  Y(x): PS   out: NS
    X(angle): ZE  Y(x): ZE   out: ZE
    X(angle): ZE  Y(x): NS   out: NS
    X(angle): ZE  Y(x): NL   out: PM
    X(angle): PS  Y(x): PL   out: PS
    X(angle): PS  Y(x): PS   out: PL
    X(angle): PS  Y(x): ZE   out: PS
    X(angle): PS  Y(x): NS   out: PM
    X(angle): PS  Y(x): NL   out: PS
    X(angle): PL  Y(x): PL   out: PVL
    X(angle): PL  Y(x): PS   out: PS
    X(angle): PL  Y(x): ZE   out: PL
    X(angle): PL  Y(x): NS   out: PS
    X(angle): PL  Y(x): NL   out: PM
 */
//MembershipFunction---------------------------------------------------------------
void initMembershipFunctions(fuzzy_system_rec *fl) {

    //enter the appropriate membership function initialisations here
    fl->inp_mem_fns[INPUT_Y][in_nl] = init_trapz (0,0, -2.1, -1.3, left_trapezoid);

    fl->inp_mem_fns[INPUT_Y][in_ns] = init_trapz (-2.1, -1.3, -1.0, 0, regular_trapezoid);

    fl->inp_mem_fns[INPUT_Y][in_ze] = init_trapz (-1.0, -0.5, 0.5, 1.0, regular_trapezoid);

    fl->inp_mem_fns[INPUT_Y][in_ps] = init_trapz (0, 1.0, 1.3, 2.1, regular_trapezoid);

    fl->inp_mem_fns[INPUT_Y][in_pl] = init_trapz (1.3, 2.1, 0, 0, right_trapezoid);

    //2 inputs
    //X
    fl->inp_mem_fns[INPUT_X][in_nl] = convert_degree_init_trap (0, 0, -30, -9, left_trapezoid);

    fl->inp_mem_fns[INPUT_X][in_ns] = convert_degree_init_trap (-10, -8, -3, 0, regular_trapezoid);

    fl->inp_mem_fns[INPUT_X][in_ze] = convert_degree_init_trap (-0.5, 0, 0, 0.5, regular_trapezoid);

    fl->inp_mem_fns[INPUT_X][in_ps] = convert_degree_init_trap (0, 3, 8, 10, regular_trapezoid);

    fl->inp_mem_fns[INPUT_X][in_pl] = convert_degree_init_trap (9, 30, 0, 0, right_trapezoid);


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
    fl->no_of_outputs = 9;


    coefficient_A=3;
    coefficient_B=0.4;
    coefficient_C=4.5;
    coefficient_D=4;

    //Sample only out_nvl,out_nl,out_nm, out_ns, out_ze,out_ps, out_pm,out_pl, out_pvl

    fl->output_values [out_nvl] = -800.0;
    fl->output_values [out_nl] = -600.0;
    fl->output_values [out_nm] = -400.0;
    fl->output_values [out_ns] = -200.0;
    fl->output_values [out_ze] = 0;
    fl->output_values [out_ps] = 200.0;
    fl->output_values [out_pm] = 400.0;
    fl->output_values [out_pl] = 600.0;
    fl->output_values [out_pvl] = 800.0;




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

