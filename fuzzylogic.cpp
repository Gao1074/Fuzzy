#include <algorithm>
#include "fuzzylogic.h"

/////////////////////////////////////////////////////////////////

//Initialise Fuzzy Rules


//rule -------------------------------------
void initFuzzyRules(fuzzy_system_rec *fl) {
	
    const int no_of_XY_rules = 25;
    for (int i = 0;i < no_of_XY_rules;i++) {
        fl->rules[i].inp_index[0] = INPUT_X;
        fl->rules[i].inp_index[1] = INPUT_Y;
    }
    for (int i = 0; i < no_of_XY_rules; ++i) {
        fl->rules[i].inp_fuzzy_set[0] = (i / 5);
        fl->rules[i].inp_fuzzy_set[1] = (i % 5) ;

        fl->rules[i].out_fuzzy_set = 4 - (i % 5) + (i / 5);
        cout <<"X(angle): "<<fl->rules[i].inp_fuzzy_set[0]<<"  Y(x): "<<fl->rules[i].inp_fuzzy_set[1]<<"   out: "<<fl-> rules[i].out_fuzzy_set<<endl;
    }

}

//隶属函数---------------------------------------------------------------
void initMembershipFunctions(fuzzy_system_rec *fl) {
    //2 inputs
    //X
    fl->inp_mem_fns[INPUT_Y][in_nl] = init_trapz (0,0,-2.1,-1.5,left_trapezoid);

    fl->inp_mem_fns[INPUT_Y][in_ns] = init_trapz (-2,-1.5,-0.7,0,regular_trapezoid);

    fl->inp_mem_fns[INPUT_Y][in_ze] = init_trapz (-0.05,0,0,0.05,regular_trapezoid);

    fl->inp_mem_fns[INPUT_Y][in_ps] = init_trapz (0,0.7,1.5,2,regular_trapezoid);

    fl->inp_mem_fns[INPUT_Y][in_pl] = init_trapz (1.5,2.1,0,0,right_trapezoid);
    //Y
    fl->inp_mem_fns[INPUT_X][in_nl] = init_trapz (0,0,-1.57,-0.52,left_trapezoid);

    fl->inp_mem_fns[INPUT_X][in_ns] = init_trapz (-0.785,-0.52,-0.26,0,regular_trapezoid);

    fl->inp_mem_fns[INPUT_X][in_ze] = init_trapz (-0.17,0,0,0.17,regular_trapezoid);

    fl->inp_mem_fns[INPUT_X][in_ps] = init_trapz (0,0.26,0.52,0.785,regular_trapezoid);

    fl->inp_mem_fns[INPUT_X][in_pl] = init_trapz (0.52,1.57,0,0,right_trapezoid);

   return;
}

void initFuzzySystem (fuzzy_system_rec *fl) {

   //Note: The settings of these parameters will depend upon your fuzzy system design
   fl->no_of_inputs = 2;  /* Inputs are handled 2 at a time only */
   fl->no_of_rules = 25;
   fl->no_of_inp_regions = 5;
   fl->no_of_outputs = 9;
	
   coefficient_A=2;
   coefficient_B=1;
   coefficient_C=1;
   coefficient_D=0.25;
	
	//Sample only out_nvl,out_nl,out_nm, out_ns, out_ze,out_ps, out_pm,out_pl, out_pvl
	// fl->output_values [out_nvl]=-95.0;
	// fl->output_values [out_nl] = -85.0;
    fl->output_values [out_nvl] = -400.0;
    fl->output_values [out_nl] = -200.0;
    fl->output_values [out_nm] = -100.0;
    fl->output_values [out_ns] = -50.0;
    fl->output_values [out_ze] = 0;
    fl->output_values [out_ps] = 50.0;
    fl->output_values [out_pm] = 100.0;
    fl->output_values [out_pl] = 200.0;
    fl->output_values [out_pvl] = 400.0;


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

