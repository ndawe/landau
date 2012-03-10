/* ranlan.F -- translated by f2c (version 20090411).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include <math.h>

/* $Id: ranlan.F,v 1.1.1.1 1996/04/01 15:02:43 mclareni Exp $ */

/* $Log: ranlan.F,v $ */
/* Revision 1.1.1.1  1996/04/01 15:02:43  mclareni */
/* Mathlib gen */


/*     This will be RANLAN,IF=DOUBLE and RANLAN64,IF=-DOUBLE */
double ranlan_(double *x)
{
    /* Initialized data */

    static double f[977] = { -2.244733f,-2.204365f,-2.168163f,-2.135219f,
	    -2.104898f,-2.07674f,-2.050397f,-2.025605f,-2.00215f,-1.979866f,
	    -1.958612f,-1.938275f,-1.91876f,-1.899984f,-1.881879f,-1.864385f,
	    -1.847451f,-1.83103f,-1.815083f,-1.799574f,-1.784473f,-1.769751f,
	    -1.755383f,-1.741346f,-1.72762f,-1.714187f,-1.701029f,-1.68813f,
	    -1.675477f,-1.663057f,-1.650858f,-1.638868f,-1.627078f,-1.615477f,
	    -1.604058f,-1.592811f,-1.581729f,-1.570806f,-1.560034f,-1.549407f,
	    -1.538919f,-1.528565f,-1.518339f,-1.508237f,-1.498254f,-1.488386f,
	    -1.478628f,-1.468976f,-1.459428f,-1.449979f,-1.440626f,-1.431365f,
	    -1.422195f,-1.413111f,-1.404112f,-1.395194f,-1.386356f,-1.377594f,
	    -1.368906f,-1.360291f,-1.351746f,-1.343269f,-1.334859f,-1.326512f,
	    -1.318229f,-1.310006f,-1.301843f,-1.293737f,-1.285688f,-1.277693f,
	    -1.269752f,-1.261863f,-1.254024f,-1.246235f,-1.238494f,-1.2308f,
	    -1.223153f,-1.21555f,-1.20799f,-1.200474f,-1.192999f,-1.185566f,
	    -1.178172f,-1.170817f,-1.1635f,-1.15622f,-1.148977f,-1.14177f,
	    -1.134598f,-1.127459f,-1.120354f,-1.113282f,-1.106242f,-1.099233f,
	    -1.092255f,-1.085306f,-1.078388f,-1.071498f,-1.064636f,-1.057802f,
	    -1.050996f,-1.044215f,-1.037461f,-1.030733f,-1.024029f,-1.01735f,
	    -1.010695f,-1.004064f,-.997456f,-.990871f,-.984308f,-.977767f,
	    -.971247f,-.964749f,-.958271f,-.951813f,-.945375f,-.938957f,
	    -.932558f,-.926178f,-.919816f,-.913472f,-.907146f,-.900838f,
	    -.894547f,-.888272f,-.882014f,-.875773f,-.869547f,-.863337f,
	    -.857142f,-.850963f,-.844798f,-.838648f,-.832512f,-.82639f,
	    -.820282f,-.814187f,-.808106f,-.802038f,-.795982f,-.78994f,
	    -.783909f,-.777891f,-.771884f,-.765889f,-.759906f,-.753934f,
	    -.747973f,-.742023f,-.736084f,-.730155f,-.724237f,-.718328f,
	    -.712429f,-.706541f,-.700661f,-.694791f,-.688931f,-.683079f,
	    -.677236f,-.671402f,-.665576f,-.659759f,-.65395f,-.648149f,
	    -.642356f,-.63657f,-.630793f,-.625022f,-.619259f,-.613503f,
	    -.607754f,-.602012f,-.596276f,-.590548f,-.584825f,-.579109f,
	    -.573399f,-.567695f,-.561997f,-.556305f,-.550618f,-.544937f,
	    -.539262f,-.533592f,-.527926f,-.522266f,-.516611f,-.510961f,
	    -.505315f,-.499674f,-.494037f,-.488405f,-.482777f,-.477153f,
	    -.471533f,-.465917f,-.460305f,-.454697f,-.449092f,-.443491f,
	    -.437893f,-.432299f,-.426707f,-.421119f,-.415534f,-.409951f,
	    -.404372f,-.398795f,-.393221f,-.387649f,-.38208f,-.376513f,
	    -.370949f,-.365387f,-.359826f,-.354268f,-.348712f,-.343157f,
	    -.337604f,-.332053f,-.326503f,-.320955f,-.315408f,-.309863f,
	    -.304318f,-.298775f,-.293233f,-.287692f,-.282152f,-.276613f,
	    -.271074f,-.265536f,-.259999f,-.254462f,-.248926f,-.243389f,
	    -.237854f,-.232318f,-.226783f,-.221247f,-.215712f,-.210176f,
	    -.204641f,-.199105f,-.193568f,-.188032f,-.182495f,-.176957f,
	    -.171419f,-.16588f,-.160341f,-.1548f,-.149259f,-.143717f,
	    -.138173f,-.132629f,-.127083f,-.121537f,-.115989f,-.110439f,
	    -.104889f,-.099336f,-.093782f,-.088227f,-.08267f,-.077111f,
	    -.07155f,-.065987f,-.060423f,-.054856f,-.049288f,-.043717f,
	    -.038144f,-.032569f,-.026991f,-.021411f,-.015828f,-.010243f,
	    -.004656f,9.34e-4f,.006527f,.012123f,.017722f,.023323f,.028928f,
	    .034535f,.040146f,.045759f,.051376f,.056997f,.06262f,.068247f,
	    .073877f,.079511f,.085149f,.09079f,.096435f,.102083f,.107736f,
	    .113392f,.119052f,.124716f,.130385f,.136057f,.141734f,.147414f,
	    .1531f,.158789f,.164483f,.170181f,.175884f,.181592f,.187304f,
	    .193021f,.198743f,.204469f,.210201f,.215937f,.221678f,.227425f,
	    .233177f,.238933f,.244696f,.250463f,.256236f,.262014f,.267798f,
	    .273587f,.279382f,.285183f,.290989f,.296801f,.302619f,.308443f,
	    .314273f,.320109f,.325951f,.331799f,.337654f,.343515f,.349382f,
	    .355255f,.361135f,.367022f,.372915f,.378815f,.384721f,.390634f,
	    .396554f,.402481f,.408415f,.414356f,.420304f,.42626f,.432222f,
	    .438192f,.444169f,.450153f,.456145f,.462144f,.468151f,.474166f,
	    .480188f,.486218f,.492256f,.498302f,.504356f,.510418f,.516488f,
	    .522566f,.528653f,.534747f,.54085f,.546962f,.553082f,.55921f,
	    .565347f,.571493f,.577648f,.583811f,.589983f,.596164f,.602355f,
	    .608554f,.614762f,.62098f,.627207f,.633444f,.639689f,.645945f,
	    .65221f,.658484f,.664768f,.671062f,.677366f,.68368f,.690004f,
	    .696338f,.702682f,.709036f,.7154f,.721775f,.72816f,.734556f,
	    .740963f,.747379f,.753807f,.760246f,.766695f,.773155f,.779627f,
	    .786109f,.792603f,.799107f,.805624f,.812151f,.81869f,.825241f,
	    .831803f,.838377f,.844962f,.85156f,.85817f,.864791f,.871425f,
	    .878071f,.884729f,.891399f,.898082f,.904778f,.911486f,.918206f,
	    .92494f,.931686f,.938446f,.945218f,.952003f,.958802f,.965614f,
	    .972439f,.979278f,.98613f,.992996f,.999875f,1.006769f,1.013676f,
	    1.020597f,1.027533f,1.034482f,1.041446f,1.048424f,1.055417f,
	    1.062424f,1.069446f,1.076482f,1.083534f,1.0906f,1.097681f,
	    1.104778f,1.111889f,1.119016f,1.126159f,1.133316f,1.14049f,
	    1.147679f,1.154884f,1.162105f,1.169342f,1.176595f,1.183864f,
	    1.191149f,1.198451f,1.20577f,1.213105f,1.220457f,1.227826f,
	    1.235211f,1.242614f,1.250034f,1.257471f,1.264926f,1.272398f,
	    1.279888f,1.287395f,1.294921f,1.302464f,1.310026f,1.317605f,
	    1.325203f,1.332819f,1.340454f,1.348108f,1.35578f,1.363472f,
	    1.371182f,1.378912f,1.38666f,1.394429f,1.402216f,1.410024f,
	    1.417851f,1.425698f,1.433565f,1.441453f,1.44936f,1.457288f,
	    1.465237f,1.473206f,1.481196f,1.489208f,1.49724f,1.505293f,
	    1.513368f,1.521465f,1.529583f,1.537723f,1.545885f,1.554068f,
	    1.562275f,1.570503f,1.578754f,1.587028f,1.595325f,1.603644f,
	    1.611987f,1.620353f,1.628743f,1.637156f,1.645593f,1.654053f,
	    1.662538f,1.671047f,1.679581f,1.688139f,1.696721f,1.705329f,
	    1.713961f,1.722619f,1.731303f,1.740011f,1.748746f,1.757506f,
	    1.766293f,1.775106f,1.783945f,1.79281f,1.801703f,1.810623f,
	    1.819569f,1.828543f,1.837545f,1.846574f,1.855631f,1.864717f,
	    1.87383f,1.882972f,1.892143f,1.901343f,1.910572f,1.91983f,
	    1.929117f,1.938434f,1.947781f,1.957158f,1.966566f,1.976004f,
	    1.985473f,1.994972f,2.004503f,2.014065f,2.023659f,2.033285f,
	    2.042943f,2.052633f,2.062355f,2.07211f,2.081899f,2.09172f,
	    2.101575f,2.111464f,2.121386f,2.131343f,2.141334f,2.15136f,
	    2.161421f,2.171517f,2.181648f,2.191815f,2.202018f,2.212257f,
	    2.222533f,2.232845f,2.243195f,2.253582f,2.264006f,2.274468f,
	    2.284968f,2.295507f,2.306084f,2.316701f,2.327356f,2.338051f,
	    2.348786f,2.359562f,2.370377f,2.381234f,2.392131f,2.40307f,
	    2.414051f,2.425073f,2.436138f,2.447246f,2.458397f,2.469591f,
	    2.480828f,2.49211f,2.503436f,2.514807f,2.526222f,2.537684f,
	    2.54919f,2.560743f,2.572343f,2.583989f,2.595682f,2.607423f,
	    2.619212f,2.63105f,2.642936f,2.654871f,2.666855f,2.67889f,
	    2.690975f,2.70311f,2.715297f,2.727535f,2.739825f,2.752168f,
	    2.764563f,2.777012f,2.789514f,2.80207f,2.814681f,2.827347f,
	    2.840069f,2.852846f,2.86568f,2.87857f,2.891518f,2.904524f,
	    2.917588f,2.930712f,2.943894f,2.957136f,2.970439f,2.983802f,
	    2.997227f,3.010714f,3.024263f,3.037875f,3.051551f,3.06529f,
	    3.079095f,3.092965f,3.1069f,3.120902f,3.134971f,3.149107f,
	    3.163312f,3.177585f,3.191928f,3.20634f,3.220824f,3.235378f,
	    3.250005f,3.264704f,3.279477f,3.294323f,3.309244f,3.32424f,
	    3.339312f,3.354461f,3.369687f,3.384992f,3.400375f,3.415838f,
	    3.431381f,3.447005f,3.462711f,3.4785f,3.494372f,3.510328f,
	    3.52637f,3.542497f,3.558711f,3.575012f,3.591402f,3.607881f,
	    3.62445f,3.641111f,3.657863f,3.674708f,3.691646f,3.70868f,
	    3.725809f,3.743034f,3.760357f,3.777779f,3.7953f,3.812921f,
	    3.830645f,3.84847f,3.8664f,3.884434f,3.902574f,3.920821f,
	    3.939176f,3.95764f,3.976215f,3.994901f,4.013699f,4.032612f,
	    4.051639f,4.070783f,4.090045f,4.109425f,4.128925f,4.148547f,
	    4.168292f,4.18816f,4.208154f,4.228275f,4.248524f,4.268903f,
	    4.289413f,4.310056f,4.330832f,4.351745f,4.372794f,4.393982f,
	    4.41531f,4.436781f,4.458395f,4.480154f,4.50206f,4.524114f,
	    4.546319f,4.568676f,4.591187f,4.613854f,4.636678f,4.659662f,
	    4.682807f,4.706116f,4.72959f,4.753231f,4.777041f,4.801024f,
	    4.825179f,4.849511f,4.87402f,4.89871f,4.923582f,4.948639f,
	    4.973883f,4.999316f,5.024942f,5.050761f,5.076778f,5.102993f,
	    5.129411f,5.156034f,5.182864f,5.209903f,5.237156f,5.264625f,
	    5.292312f,5.32022f,5.348354f,5.376714f,5.405306f,5.434131f,
	    5.463193f,5.492496f,5.522042f,5.551836f,5.58188f,5.612178f,
	    5.642734f,5.673552f,5.704634f,5.735986f,5.76761f,5.799512f,
	    5.831694f,5.864161f,5.896918f,5.929968f,5.963316f,5.996967f,
	    6.030925f,6.065194f,6.09978f,6.134687f,6.169921f,6.205486f,
	    6.241387f,6.27763f,6.31422f,6.351163f,6.388465f,6.42613f,
	    6.464166f,6.502578f,6.541371f,6.580553f,6.62013f,6.660109f,
	    6.700495f,6.741297f,6.78252f,6.824173f,6.866262f,6.908795f,
	    6.95178f,6.995225f,7.039137f,7.083525f,7.128398f,7.173764f,
	    7.219632f,7.266011f,7.31291f,7.360339f,7.408308f,7.456827f,
	    7.505905f,7.555554f,7.605785f,7.656608f,7.708035f,7.760077f,
	    7.812747f,7.866057f,7.920019f,7.974647f,8.029953f,8.085952f,
	    8.142657f,8.200083f,8.258245f,8.317158f,8.376837f,8.4373f,
	    8.498562f,8.560641f,8.623554f,8.687319f,8.751955f,8.817481f,
	    8.883916f,8.951282f,9.0196f,9.088889f,9.159174f,9.230477f,
	    9.302822f,9.376233f,9.450735f,9.526355f,9.603118f,9.681054f,
	    9.760191f,9.840558f,9.922186f,10.005107f,10.089353f,10.174959f,
	    10.261958f,10.350389f,10.440287f,10.531693f,10.624646f,10.719188f,
	    10.815362f,10.913214f,11.012789f,11.114137f,11.217307f,11.322352f,
	    11.429325f,11.538283f,11.649285f,11.76239f,11.877664f,11.99517f,
	    12.114979f,12.237161f,12.361791f,12.488946f,12.618708f,12.751161f,
	    12.886394f,13.024498f,13.16557f,13.309711f,13.457026f,13.607625f,
	    13.761625f,13.919145f,14.080314f,14.245263f,14.414134f,14.587072f,
	    14.764233f,14.945778f,15.131877f,15.322712f,15.51847f,15.719353f,
	    15.92557f,16.137345f,16.354912f,16.57852f,16.808433f,17.044929f,
	    17.288305f,17.538873f,17.796967f,18.062943f,18.337176f,18.620068f,
	    18.912049f,19.213574f,19.525133f,19.847249f,20.18048f,20.525429f,
	    20.882738f,21.253102f,21.637266f,22.036036f,22.450278f,22.880933f,
	    23.329017f,23.795634f,24.281981f,24.789364f,25.319207f,25.873062f,
	    26.452634f,27.059789f,27.696581f,28.365274f,29.06837f,29.808638f,
	    30.589157f,31.413354f,32.28506f,33.208568f,34.188705f,35.23092f,
	    36.341388f,37.527131f,38.796172f,40.157721f,41.622399f,43.202525f,
	    44.912465f,46.769077f,48.792279f,51.005773f,53.437996f,56.123356f,
	    59.103894f };

    /* System generated locals */
    double ret_val, r__1;

    /* Local variables */
    static int i__;
    static double u, v;

    u = 1000 * *x;
    i__ = u;
    u -= i__;
    if (i__ >= 70 && i__ <= 800) {
	ret_val = f[i__ - 6] + u * (f[i__ - 5] - f[i__ - 6]);
    } else if (i__ >= 7 && i__ <= 980) {
	ret_val = f[i__ - 6] + u * (f[i__ - 5] - f[i__ - 6] - (1 - u) * .25f *
		 (f[i__ - 4] - f[i__ - 5] - f[i__ - 6] + f[i__ - 7]));
    } else if (i__ < 7) {
	v = log(*x);
	u = 1 / v;
	ret_val = ((u * 17.0854528f + 34.5213058f) * u + .9985895f) / ((u * 
		4.01244582f + 34.1760202f) * u + 1) * (-log(-.91893853f - v) 
		- 1);
    } else {
	u = 1 - *x;
/* Computing 2nd power */
	r__1 = u;
	v = r__1 * r__1;
	if (*x <= .999f) {
	    ret_val = (u * 263.991156f + 1.00060006f + v * 4373.20068f) / ((u 
		    * 257.368075f + 1 + v * 3414.48018f) * u);
	} else {
	    ret_val = (u * 6075.14119f + 1.00001538f + v * 734266.409f) / ((u 
		    * 6065.11919f + 1 + v * 694021.044f) * u);
	}
    }
    return ret_val;
} /* ranlan_ */

