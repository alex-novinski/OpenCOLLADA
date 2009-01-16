/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BRUSH_H__
#define __MayaDM_BRUSH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Brush : public DependNode
{
public:
	struct LeafCurl{
		float leafCurl_Position;
		float leafCurl_FloatValue;
		unsigned int leafCurl_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", leafCurl_Position);
			fprintf(file,"%f ", leafCurl_FloatValue);
			fprintf(file,"%i", leafCurl_Interp);
		}
	};
	struct PetalCurl{
		float petalCurl_Position;
		float petalCurl_FloatValue;
		unsigned int petalCurl_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", petalCurl_Position);
			fprintf(file,"%f ", petalCurl_FloatValue);
			fprintf(file,"%i", petalCurl_Interp);
		}
	};
	struct WidthScale{
		float widthScale_Position;
		float widthScale_FloatValue;
		unsigned int widthScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", widthScale_Position);
			fprintf(file,"%f ", widthScale_FloatValue);
			fprintf(file,"%i", widthScale_Interp);
		}
	};
	struct LeafWidthScale{
		float leafWidthScale_Position;
		float leafWidthScale_FloatValue;
		unsigned int leafWidthScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", leafWidthScale_Position);
			fprintf(file,"%f ", leafWidthScale_FloatValue);
			fprintf(file,"%i", leafWidthScale_Interp);
		}
	};
	struct PetalWidthScale{
		float petalWidthScale_Position;
		float petalWidthScale_FloatValue;
		unsigned int petalWidthScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", petalWidthScale_Position);
			fprintf(file,"%f ", petalWidthScale_FloatValue);
			fprintf(file,"%i", petalWidthScale_Interp);
		}
	};
	struct TwigLengthScale{
		float twigLengthScale_Position;
		float twigLengthScale_FloatValue;
		unsigned int twigLengthScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", twigLengthScale_Position);
			fprintf(file,"%f ", twigLengthScale_FloatValue);
			fprintf(file,"%i", twigLengthScale_Interp);
		}
	};
	struct Environment{
		float environment_Position;
		float3 environment_Color;
		unsigned int environment_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", environment_Position);
			environment_Color.write(file);
			fprintf(file, " ");
			fprintf(file,"%i", environment_Interp);
		}
	};
	struct ReflectionRolloff{
		float reflectionRolloff_Position;
		float reflectionRolloff_FloatValue;
		unsigned int reflectionRolloff_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", reflectionRolloff_Position);
			fprintf(file,"%f ", reflectionRolloff_FloatValue);
			fprintf(file,"%i", reflectionRolloff_Interp);
		}
	};
public:
	Brush(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "brush"){}
	virtual ~Brush(){}
	void setGlobalScale(double gsc)
	{
		if(gsc == 1.0) return;
		fprintf(mFile,"setAttr \".gsc\" %f;\n", gsc);

	}
	void setDepth(bool dep)
	{
		if(dep == false) return;
		fprintf(mFile,"setAttr \".dep\" %i;\n", dep);

	}
	void setModifyDepth(bool mdp)
	{
		if(mdp == true) return;
		fprintf(mFile,"setAttr \".mdp\" %i;\n", mdp);

	}
	void setModifyColor(bool mdc)
	{
		if(mdc == true) return;
		fprintf(mFile,"setAttr \".mdc\" %i;\n", mdc);

	}
	void setModifyAlpha(bool mda)
	{
		if(mda == true) return;
		fprintf(mFile,"setAttr \".mda\" %i;\n", mda);

	}
	void setIlluminated(bool ill)
	{
		if(ill == false) return;
		fprintf(mFile,"setAttr \".ill\" %i;\n", ill);

	}
	void setCastShadows(bool csd)
	{
		if(csd == false) return;
		fprintf(mFile,"setAttr \".csd\" %i;\n", csd);

	}
	void setLightingBasedWidth(double lbw)
	{
		if(lbw == 0.0) return;
		fprintf(mFile,"setAttr \".lbw\" %f;\n", lbw);

	}
	void setBranches(bool brc)
	{
		if(brc == false) return;
		fprintf(mFile,"setAttr \".brc\" %i;\n", brc);

	}
	void setTwigs(bool twg)
	{
		if(twg == false) return;
		fprintf(mFile,"setAttr \".twg\" %i;\n", twg);

	}
	void setBuds(bool bud)
	{
		if(bud == false) return;
		fprintf(mFile,"setAttr \".bud\" %i;\n", bud);

	}
	void setLeaves(bool lvs)
	{
		if(lvs == false) return;
		fprintf(mFile,"setAttr \".lvs\" %i;\n", lvs);

	}
	void setFlowers(bool flw)
	{
		if(flw == false) return;
		fprintf(mFile,"setAttr \".flw\" %i;\n", flw);

	}
	void setBrushType(unsigned int brt)
	{
		if(brt == 0) return;
		fprintf(mFile,"setAttr \".brt\" %i;\n", brt);

	}
	void setBrushWidth(double bwd)
	{
		if(bwd == 0.05) return;
		fprintf(mFile,"setAttr \".bwd\" %f;\n", bwd);

	}
	void setScreenspaceWidth(bool spw)
	{
		if(spw == false) return;
		fprintf(mFile,"setAttr \".spw\" %i;\n", spw);

	}
	void setDistanceScaling(double dsl)
	{
		if(dsl == 0.0) return;
		fprintf(mFile,"setAttr \".dsl\" %f;\n", dsl);

	}
	void setMinPixelWidth(double mpw)
	{
		if(mpw == 0.0) return;
		fprintf(mFile,"setAttr \".mpw\" %f;\n", mpw);

	}
	void setMaxPixelWidth(double mxp)
	{
		if(mxp == 1000.0) return;
		fprintf(mFile,"setAttr \".mxp\" %f;\n", mxp);

	}
	void setStampDensity(double sdn)
	{
		if(sdn == 8.0) return;
		fprintf(mFile,"setAttr \".sdn\" %f;\n", sdn);

	}
	void setSoftness(double sft)
	{
		if(sft == 0.2) return;
		fprintf(mFile,"setAttr \".sft\" %f;\n", sft);

	}
	void setEdgeAntialias(bool eaa)
	{
		if(eaa == true) return;
		fprintf(mFile,"setAttr \".eaa\" %i;\n", eaa);

	}
	void setEdgeClip(bool ecl)
	{
		if(ecl == false) return;
		fprintf(mFile,"setAttr \".ecl\" %i;\n", ecl);

	}
	void setEdgeClipDepth(double ecd)
	{
		if(ecd == 0.1) return;
		fprintf(mFile,"setAttr \".ecd\" %f;\n", ecd);

	}
	void setOcclusionWidthScale(bool ows)
	{
		if(ows == false) return;
		fprintf(mFile,"setAttr \".ows\" %i;\n", ows);

	}
	void setBlurIntensity(int bin)
	{
		if(bin == 4) return;
		fprintf(mFile,"setAttr \".bin\" %i;\n", bin);

	}
	void setColor1(const float3& cl1)
	{
		fprintf(mFile,"setAttr \".cl1\" -type \"float3\" ");
		cl1.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColor1R(float c1r)
	{
		if(c1r == 0.0) return;
		fprintf(mFile,"setAttr \".cl1.c1r\" %f;\n", c1r);

	}
	void setColor1G(float c1g)
	{
		if(c1g == 0.0) return;
		fprintf(mFile,"setAttr \".cl1.c1g\" %f;\n", c1g);

	}
	void setColor1B(float c1b)
	{
		if(c1b == 0.0) return;
		fprintf(mFile,"setAttr \".cl1.c1b\" %f;\n", c1b);

	}
	void setColor2(const float3& cl2)
	{
		fprintf(mFile,"setAttr \".cl2\" -type \"float3\" ");
		cl2.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColor2R(float c2r)
	{
		if(c2r == 1.0) return;
		fprintf(mFile,"setAttr \".cl2.c2r\" %f;\n", c2r);

	}
	void setColor2G(float c2g)
	{
		if(c2g == 1.0) return;
		fprintf(mFile,"setAttr \".cl2.c2g\" %f;\n", c2g);

	}
	void setColor2B(float c2b)
	{
		if(c2b == 1.0) return;
		fprintf(mFile,"setAttr \".cl2.c2b\" %f;\n", c2b);

	}
	void setTransparency1(const float3& tn1)
	{
		fprintf(mFile,"setAttr \".tn1\" -type \"float3\" ");
		tn1.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTransparency1R(float t1r)
	{
		if(t1r == 0.0) return;
		fprintf(mFile,"setAttr \".tn1.t1r\" %f;\n", t1r);

	}
	void setTransparency1G(float t1g)
	{
		if(t1g == 0.0) return;
		fprintf(mFile,"setAttr \".tn1.t1g\" %f;\n", t1g);

	}
	void setTransparency1B(float t1b)
	{
		if(t1b == 0.0) return;
		fprintf(mFile,"setAttr \".tn1.t1b\" %f;\n", t1b);

	}
	void setTransparency2(const float3& tn2)
	{
		fprintf(mFile,"setAttr \".tn2\" -type \"float3\" ");
		tn2.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTransparency2R(float t2r)
	{
		if(t2r == 0.0) return;
		fprintf(mFile,"setAttr \".tn2.t2r\" %f;\n", t2r);

	}
	void setTransparency2G(float t2g)
	{
		if(t2g == 0.0) return;
		fprintf(mFile,"setAttr \".tn2.t2g\" %f;\n", t2g);

	}
	void setTransparency2B(float t2b)
	{
		if(t2b == 0.0) return;
		fprintf(mFile,"setAttr \".tn2.t2b\" %f;\n", t2b);

	}
	void setIncandescence1(const float3& in1)
	{
		fprintf(mFile,"setAttr \".in1\" -type \"float3\" ");
		in1.write(mFile);
		fprintf(mFile,";\n");

	}
	void setIncandescence1R(float i1r)
	{
		if(i1r == 0.0) return;
		fprintf(mFile,"setAttr \".in1.i1r\" %f;\n", i1r);

	}
	void setIncandescence1G(float i1g)
	{
		if(i1g == 0.0) return;
		fprintf(mFile,"setAttr \".in1.i1g\" %f;\n", i1g);

	}
	void setIncandescence1B(float i1b)
	{
		if(i1b == 0.0) return;
		fprintf(mFile,"setAttr \".in1.i1b\" %f;\n", i1b);

	}
	void setIncandescence2(const float3& in2)
	{
		fprintf(mFile,"setAttr \".in2\" -type \"float3\" ");
		in2.write(mFile);
		fprintf(mFile,";\n");

	}
	void setIncandescence2R(float i2r)
	{
		if(i2r == 0.0) return;
		fprintf(mFile,"setAttr \".in2.i2r\" %f;\n", i2r);

	}
	void setIncandescence2G(float i2g)
	{
		if(i2g == 0.0) return;
		fprintf(mFile,"setAttr \".in2.i2g\" %f;\n", i2g);

	}
	void setIncandescence2B(float i2b)
	{
		if(i2b == 0.0) return;
		fprintf(mFile,"setAttr \".in2.i2b\" %f;\n", i2b);

	}
	void setSpecularColor(const float3& spc)
	{
		fprintf(mFile,"setAttr \".spc\" -type \"float3\" ");
		spc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSpecularColorR(float spr)
	{
		if(spr == 1.0) return;
		fprintf(mFile,"setAttr \".spc.spr\" %f;\n", spr);

	}
	void setSpecularColorG(float spg)
	{
		if(spg == 1.0) return;
		fprintf(mFile,"setAttr \".spc.spg\" %f;\n", spg);

	}
	void setSpecularColorB(float spb)
	{
		if(spb == 1.0) return;
		fprintf(mFile,"setAttr \".spc.spb\" %f;\n", spb);

	}
	void setSpecular(double spe)
	{
		if(spe == 0.0) return;
		fprintf(mFile,"setAttr \".spe\" %f;\n", spe);

	}
	void setSpecularPower(double spp)
	{
		if(spp == 10.0) return;
		fprintf(mFile,"setAttr \".spp\" %f;\n", spp);

	}
	void setTranslucence(double trn)
	{
		if(trn == 0.2) return;
		fprintf(mFile,"setAttr \".trn\" %f;\n", trn);

	}
	void setGlow(double glw)
	{
		if(glw == 0.0) return;
		fprintf(mFile,"setAttr \".glw\" %f;\n", glw);

	}
	void setGlowColor(const float3& glc)
	{
		fprintf(mFile,"setAttr \".glc\" -type \"float3\" ");
		glc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setGlowColorR(float glr)
	{
		if(glr == 0.5) return;
		fprintf(mFile,"setAttr \".glc.glr\" %f;\n", glr);

	}
	void setGlowColorG(float glg)
	{
		if(glg == 0.5) return;
		fprintf(mFile,"setAttr \".glc.glg\" %f;\n", glg);

	}
	void setGlowColorB(float glb)
	{
		if(glb == 0.5) return;
		fprintf(mFile,"setAttr \".glc.glb\" %f;\n", glb);

	}
	void setGlowSpread(double gls)
	{
		if(gls == 3.0) return;
		fprintf(mFile,"setAttr \".gls\" %f;\n", gls);

	}
	void setShaderGlow(double sgl)
	{
		if(sgl == 0.0) return;
		fprintf(mFile,"setAttr \".sgl\" %f;\n", sgl);

	}
	void setHueRand(double chr)
	{
		if(chr == 0.0) return;
		fprintf(mFile,"setAttr \".chr\" %f;\n", chr);

	}
	void setSatRand(double csr)
	{
		if(csr == 0.0) return;
		fprintf(mFile,"setAttr \".csr\" %f;\n", csr);

	}
	void setValRand(double cvr)
	{
		if(cvr == 0.0) return;
		fprintf(mFile,"setAttr \".cvr\" %f;\n", cvr);

	}
	void setRootFade(double rfd)
	{
		if(rfd == 0.0) return;
		fprintf(mFile,"setAttr \".rfd\" %f;\n", rfd);

	}
	void setTipFade(double tfd)
	{
		if(tfd == 0.0) return;
		fprintf(mFile,"setAttr \".tfd\" %f;\n", tfd);

	}
	void setFakeShadow(unsigned int fks)
	{
		if(fks == 0) return;
		fprintf(mFile,"setAttr \".fks\" %i;\n", fks);

	}
	void setShadowOffset(double sof)
	{
		if(sof == 0.5) return;
		fprintf(mFile,"setAttr \".sof\" %f;\n", sof);

	}
	void setShadowDiffusion(double sdf)
	{
		if(sdf == 0.1) return;
		fprintf(mFile,"setAttr \".sdf\" %f;\n", sdf);

	}
	void setShadowTransparency(double stn)
	{
		if(stn == 0.8) return;
		fprintf(mFile,"setAttr \".stn\" %f;\n", stn);

	}
	void setBackShadow(double bks)
	{
		if(bks == 0.0) return;
		fprintf(mFile,"setAttr \".bks\" %f;\n", bks);

	}
	void setBrightnessRand(double brn)
	{
		if(brn == 0.0) return;
		fprintf(mFile,"setAttr \".brn\" %f;\n", brn);

	}
	void setCenterShadow(double cns)
	{
		if(cns == 0.0) return;
		fprintf(mFile,"setAttr \".cns\" %f;\n", cns);

	}
	void setDepthShadowType(unsigned int dpt)
	{
		if(dpt == 0) return;
		fprintf(mFile,"setAttr \".dpt\" %i;\n", dpt);

	}
	void setDepthShadow(double dpl)
	{
		if(dpl == 0.0) return;
		fprintf(mFile,"setAttr \".dpl\" %f;\n", dpl);

	}
	void setDepthShadowDepth(double dps)
	{
		if(dps == 0.0) return;
		fprintf(mFile,"setAttr \".dps\" %f;\n", dps);

	}
	void setRealLights(bool rll)
	{
		if(rll == false) return;
		fprintf(mFile,"setAttr \".rll\" %i;\n", rll);

	}
	void setLightDirection(const double3& ldr)
	{
		fprintf(mFile,"setAttr \".ldr\" -type \"double3\" ");
		ldr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLightDirectionX(double ldx)
	{
		if(ldx == 0.5) return;
		fprintf(mFile,"setAttr \".ldr.ldx\" %f;\n", ldx);

	}
	void setLightDirectionY(double ldy)
	{
		if(ldy == 0.5) return;
		fprintf(mFile,"setAttr \".ldr.ldy\" %f;\n", ldy);

	}
	void setLightDirectionZ(double ldz)
	{
		if(ldz == -0.5) return;
		fprintf(mFile,"setAttr \".ldr.ldz\" %f;\n", ldz);

	}
	void setGapSize(double gsz)
	{
		if(gsz == 0.0) return;
		fprintf(mFile,"setAttr \".gsz\" %f;\n", gsz);

	}
	void setGapSpacing(double gsp)
	{
		if(gsp == 1.0) return;
		fprintf(mFile,"setAttr \".gsp\" %f;\n", gsp);

	}
	void setGapRand(double grn)
	{
		if(grn == 0.0) return;
		fprintf(mFile,"setAttr \".grn\" %f;\n", grn);

	}
	void setFlowSpeed(double fws)
	{
		if(fws == 0.0) return;
		fprintf(mFile,"setAttr \".fws\" %f;\n", fws);

	}
	void setTextureFlow(bool tfl)
	{
		if(tfl == true) return;
		fprintf(mFile,"setAttr \".tfl\" %i;\n", tfl);

	}
	void setTimeClip(bool tcl)
	{
		if(tcl == false) return;
		fprintf(mFile,"setAttr \".tcl\" %i;\n", tcl);

	}
	void setStrokeTime(bool srm)
	{
		if(srm == false) return;
		fprintf(mFile,"setAttr \".srm\" %i;\n", srm);

	}
	void setStartTime(double sti)
	{
		if(sti == 0.0) return;
		fprintf(mFile,"setAttr \".sti\" %f;\n", sti);

	}
	void setEndTime(double eti)
	{
		if(eti == 1000.0) return;
		fprintf(mFile,"setAttr \".eti\" %f;\n", eti);

	}
	void setTubes(bool tub)
	{
		if(tub == false) return;
		fprintf(mFile,"setAttr \".tub\" %i;\n", tub);

	}
	void setCreationScript(const string& csc)
	{
		if(csc == "NULL") return;
		fprintf(mFile,"setAttr \".csc\" -type \"string\" ");
		csc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRuntimeScript(const string& rsc)
	{
		if(rsc == "NULL") return;
		fprintf(mFile,"setAttr \".rsc\" -type \"string\" ");
		rsc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTubeCompletion(bool tcm)
	{
		if(tcm == true) return;
		fprintf(mFile,"setAttr \".tcm\" %i;\n", tcm);

	}
	void setTubesPerStep(double tps)
	{
		if(tps == 0.5) return;
		fprintf(mFile,"setAttr \".tps\" %f;\n", tps);

	}
	void setTubeRand(double trd)
	{
		if(trd == 1.0) return;
		fprintf(mFile,"setAttr \".trd\" %f;\n", trd);

	}
	void setStartTubes(int stb)
	{
		if(stb == 0) return;
		fprintf(mFile,"setAttr \".stb\" %i;\n", stb);

	}
	void setLengthMax(double lnx)
	{
		if(lnx == 1.0) return;
		fprintf(mFile,"setAttr \".lnx\" %f;\n", lnx);

	}
	void setLengthMin(double lnn)
	{
		if(lnn == 0.0) return;
		fprintf(mFile,"setAttr \".lnn\" %f;\n", lnn);

	}
	void setSegments(int sgm)
	{
		if(sgm == 10) return;
		fprintf(mFile,"setAttr \".sgm\" %i;\n", sgm);

	}
	void setTubeWidth1(double tw1)
	{
		if(tw1 == 0.01) return;
		fprintf(mFile,"setAttr \".tw1\" %f;\n", tw1);

	}
	void setTubeWidth2(double tw2)
	{
		if(tw2 == 0.01) return;
		fprintf(mFile,"setAttr \".tw2\" %f;\n", tw2);

	}
	void setWidthRand(double wdr)
	{
		if(wdr == 0.0) return;
		fprintf(mFile,"setAttr \".wdr\" %f;\n", wdr);

	}
	void setWidthBias(double wdb)
	{
		if(wdb == 0.0) return;
		fprintf(mFile,"setAttr \".wdb\" %f;\n", wdb);

	}
	void setLengthFlex(double lfx)
	{
		if(lfx == 0.0) return;
		fprintf(mFile,"setAttr \".lfx\" %f;\n", lfx);

	}
	void setSegmentLengthBias(double sgb)
	{
		if(sgb == 0.0) return;
		fprintf(mFile,"setAttr \".sgb\" %f;\n", sgb);

	}
	void setSegmentWidthBias(double swb)
	{
		if(swb == 0.0) return;
		fprintf(mFile,"setAttr \".swb\" %f;\n", swb);

	}
	void setTubeDirection(unsigned int tdr)
	{
		if(tdr == 0) return;
		fprintf(mFile,"setAttr \".tdr\" %i;\n", tdr);

	}
	void setElevationMin(double elm)
	{
		if(elm == 0.2) return;
		fprintf(mFile,"setAttr \".elm\" %f;\n", elm);

	}
	void setElevationMax(double elx)
	{
		if(elx == 0.5) return;
		fprintf(mFile,"setAttr \".elx\" %f;\n", elx);

	}
	void setAzimuthMin(double azn)
	{
		if(azn == -0.1) return;
		fprintf(mFile,"setAttr \".azn\" %f;\n", azn);

	}
	void setAzimuthMax(double azx)
	{
		if(azx == 0.1) return;
		fprintf(mFile,"setAttr \".azx\" %f;\n", azx);

	}
	void setFlatness1(double fl1)
	{
		if(fl1 == 0.0) return;
		fprintf(mFile,"setAttr \".fl1\" %f;\n", fl1);

	}
	void setFlatness2(double fl2)
	{
		if(fl2 == 0.0) return;
		fprintf(mFile,"setAttr \".fl2\" %f;\n", fl2);

	}
	void setTwist(double twi)
	{
		if(twi == 0.0) return;
		fprintf(mFile,"setAttr \".twi\" %f;\n", twi);

	}
	void setTwistRate(double twr)
	{
		if(twr == 0.0) return;
		fprintf(mFile,"setAttr \".twr\" %f;\n", twr);

	}
	void setTwistRand(double twd)
	{
		if(twd == 1.0) return;
		fprintf(mFile,"setAttr \".twd\" %f;\n", twd);

	}
	void setSpiralMin(double spm)
	{
		if(spm == 0.0) return;
		fprintf(mFile,"setAttr \".spm\" %f;\n", spm);

	}
	void setSpiralMax(double spx)
	{
		if(spx == 0.0) return;
		fprintf(mFile,"setAttr \".spx\" %f;\n", spx);

	}
	void setSpiralDecay(double spd)
	{
		if(spd == 0.0) return;
		fprintf(mFile,"setAttr \".spd\" %f;\n", spd);

	}
	void setBend(double ben)
	{
		if(ben == 0.0) return;
		fprintf(mFile,"setAttr \".ben\" %f;\n", ben);

	}
	void setBendBias(double bnb)
	{
		if(bnb == 0.0) return;
		fprintf(mFile,"setAttr \".bnb\" %f;\n", bnb);

	}
	void setDisplacementDelay(double ddl)
	{
		if(ddl == 0.2) return;
		fprintf(mFile,"setAttr \".ddl\" %f;\n", ddl);

	}
	void setWiggle(double wgl)
	{
		if(wgl == 0.0) return;
		fprintf(mFile,"setAttr \".wgl\" %f;\n", wgl);

	}
	void setWiggleFrequency(double wgf)
	{
		if(wgf == 3) return;
		fprintf(mFile,"setAttr \".wgf\" %f;\n", wgf);

	}
	void setWiggleOffset(double wgo)
	{
		if(wgo == 0.0) return;
		fprintf(mFile,"setAttr \".wgo\" %f;\n", wgo);

	}
	void setCurl(double crl)
	{
		if(crl == 0.0) return;
		fprintf(mFile,"setAttr \".crl\" %f;\n", crl);

	}
	void setCurlFrequency(double crf)
	{
		if(crf == 1) return;
		fprintf(mFile,"setAttr \".crf\" %f;\n", crf);

	}
	void setCurlOffset(double cro)
	{
		if(cro == 0.0) return;
		fprintf(mFile,"setAttr \".cro\" %f;\n", cro);

	}
	void setNoise(double noi)
	{
		if(noi == 0.0) return;
		fprintf(mFile,"setAttr \".noi\" %f;\n", noi);

	}
	void setNoiseFrequency(double nof)
	{
		if(nof == 0.2) return;
		fprintf(mFile,"setAttr \".nof\" %f;\n", nof);

	}
	void setNoiseOffset(double noo)
	{
		if(noo == 0.0) return;
		fprintf(mFile,"setAttr \".noo\" %f;\n", noo);

	}
	void setSplitMaxDepth(double smd)
	{
		if(smd == 2.0) return;
		fprintf(mFile,"setAttr \".smd\" %f;\n", smd);

	}
	void setSplitRand(double srd)
	{
		if(srd == 0.0) return;
		fprintf(mFile,"setAttr \".srd\" %f;\n", srd);

	}
	void setSplitAngle(double spa)
	{
		if(spa == 30.0) return;
		fprintf(mFile,"setAttr \".spa\" %f;\n", spa);

	}
	void setSplitSizeDecay(double ssd)
	{
		if(ssd == 0.7) return;
		fprintf(mFile,"setAttr \".ssd\" %f;\n", ssd);

	}
	void setSplitBias(double slb)
	{
		if(slb == 0.0) return;
		fprintf(mFile,"setAttr \".slb\" %f;\n", slb);

	}
	void setSplitTwist(double slt)
	{
		if(slt == 0.5) return;
		fprintf(mFile,"setAttr \".slt\" %f;\n", slt);

	}
	void setStartBranches(double sbr)
	{
		if(sbr == 0) return;
		fprintf(mFile,"setAttr \".sbr\" %f;\n", sbr);

	}
	void setNumBranches(int nbr)
	{
		if(nbr == 2) return;
		fprintf(mFile,"setAttr \".nbr\" %i;\n", nbr);

	}
	void setBranchDropout(double bdr)
	{
		if(bdr == 0.0) return;
		fprintf(mFile,"setAttr \".bdr\" %f;\n", bdr);

	}
	void setMiddleBranch(bool mbr)
	{
		if(mbr == false) return;
		fprintf(mFile,"setAttr \".mbr\" %i;\n", mbr);

	}
	void setMinSize(double mms)
	{
		if(mms == 0.0001) return;
		fprintf(mFile,"setAttr \".mms\" %f;\n", mms);

	}
	void setPathFollow(double pfl)
	{
		if(pfl == 0.0) return;
		fprintf(mFile,"setAttr \".pfl\" %f;\n", pfl);

	}
	void setPathAttract(double pat)
	{
		if(pat == 0.0) return;
		fprintf(mFile,"setAttr \".pat\" %f;\n", pat);

	}
	void setCurveFollow(double cfw)
	{
		if(cfw == 0.0) return;
		fprintf(mFile,"setAttr \".cfw\" %f;\n", cfw);

	}
	void setCurveAttract(double cva)
	{
		if(cva == 0.0) return;
		fprintf(mFile,"setAttr \".cva\" %f;\n", cva);

	}
	void setCurveMaxDist(double cmd)
	{
		if(cmd == 0.0) return;
		fprintf(mFile,"setAttr \".cmd\" %f;\n", cmd);

	}
	void setUniformForce(const double3& ufr)
	{
		fprintf(mFile,"setAttr \".ufr\" -type \"double3\" ");
		ufr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUniformForceX(double ufx)
	{
		if(ufx == 0.0) return;
		fprintf(mFile,"setAttr \".ufr.ufx\" %f;\n", ufx);

	}
	void setUniformForceY(double ufy)
	{
		if(ufy == 0.0) return;
		fprintf(mFile,"setAttr \".ufr.ufy\" %f;\n", ufy);

	}
	void setUniformForceZ(double ufz)
	{
		if(ufz == 0.0) return;
		fprintf(mFile,"setAttr \".ufr.ufz\" %f;\n", ufz);

	}
	void setTurbulenceType(unsigned int trt)
	{
		if(trt == 0) return;
		fprintf(mFile,"setAttr \".trt\" %i;\n", trt);

	}
	void setTurbulenceInterpolation(unsigned int tin)
	{
		if(tin == 0) return;
		fprintf(mFile,"setAttr \".tin\" %i;\n", tin);

	}
	void setTurbulence(double tur)
	{
		if(tur == 0.2) return;
		fprintf(mFile,"setAttr \".tur\" %f;\n", tur);

	}
	void setTurbulenceFrequency(double trf)
	{
		if(trf == 0.2) return;
		fprintf(mFile,"setAttr \".trf\" %f;\n", trf);

	}
	void setTurbulenceSpeed(double trs)
	{
		if(trs == 0.5) return;
		fprintf(mFile,"setAttr \".trs\" %f;\n", trs);

	}
	void setTurbulenceOffset(const double3& tro)
	{
		fprintf(mFile,"setAttr \".tro\" -type \"double3\" ");
		tro.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTurbulenceOffsetX(double trx)
	{
		if(trx == 0.0) return;
		fprintf(mFile,"setAttr \".tro.trx\" %f;\n", trx);

	}
	void setTurbulenceOffsetY(double try_)
	{
		if(try_ == 0.0) return;
		fprintf(mFile,"setAttr \".tro.try\" %f;\n", try_);

	}
	void setTurbulenceOffsetZ(double trz)
	{
		if(trz == 0.0) return;
		fprintf(mFile,"setAttr \".tro.trz\" %f;\n", trz);

	}
	void setRandom(double ran)
	{
		if(ran == 0.0) return;
		fprintf(mFile,"setAttr \".ran\" %f;\n", ran);

	}
	void setGravity(double grv)
	{
		if(grv == 0.0) return;
		fprintf(mFile,"setAttr \".grv\" %f;\n", grv);

	}
	void setMomentum(double mmt)
	{
		if(mmt == 1.0) return;
		fprintf(mFile,"setAttr \".mmt\" %f;\n", mmt);

	}
	void setDeflection(bool def)
	{
		if(def == false) return;
		fprintf(mFile,"setAttr \".def\" %i;\n", def);

	}
	void setDeflectionMin(double dfm)
	{
		if(dfm == 0.0) return;
		fprintf(mFile,"setAttr \".dfm\" %f;\n", dfm);

	}
	void setDeflectionMax(double dfx)
	{
		if(dfx == 0.3) return;
		fprintf(mFile,"setAttr \".dfx\" %f;\n", dfx);

	}
	void setTwigsInCluster(int tic)
	{
		if(tic == 1) return;
		fprintf(mFile,"setAttr \".tic\" %i;\n", tic);

	}
	void setTwigDropout(double tdp)
	{
		if(tdp == 0.0) return;
		fprintf(mFile,"setAttr \".tdp\" %f;\n", tdp);

	}
	void setTwigAngle1(double ta1)
	{
		if(ta1 == 90.0) return;
		fprintf(mFile,"setAttr \".ta1\" %f;\n", ta1);

	}
	void setTwigAngle2(double ta2)
	{
		if(ta2 == 80.0) return;
		fprintf(mFile,"setAttr \".ta2\" %f;\n", ta2);

	}
	void setTwigTwist(double ttw)
	{
		if(ttw == 0.0) return;
		fprintf(mFile,"setAttr \".ttw\" %f;\n", ttw);

	}
	void setTwigLength(double twl)
	{
		if(twl == 0.5) return;
		fprintf(mFile,"setAttr \".twl\" %f;\n", twl);

	}
	void setTwigStart(double tst)
	{
		if(tst == 0.5) return;
		fprintf(mFile,"setAttr \".tst\" %f;\n", tst);

	}
	void setNumTwigClusters(double ntc)
	{
		if(ntc == 4) return;
		fprintf(mFile,"setAttr \".ntc\" %f;\n", ntc);

	}
	void setTwigBaseWidth(double twb)
	{
		if(twb == 0.4) return;
		fprintf(mFile,"setAttr \".twb\" %f;\n", twb);

	}
	void setTwigTipWidth(double twt)
	{
		if(twt == 0.2) return;
		fprintf(mFile,"setAttr \".twt\" %f;\n", twt);

	}
	void setTwigStiffness(double tgs)
	{
		if(tgs == 0.5) return;
		fprintf(mFile,"setAttr \".tgs\" %f;\n", tgs);

	}
	void setBranchAfterTwigs(bool bat)
	{
		if(bat == false) return;
		fprintf(mFile,"setAttr \".bat\" %i;\n", bat);

	}
	void setLeavesInCluster(int lic)
	{
		if(lic == 1) return;
		fprintf(mFile,"setAttr \".lic\" %i;\n", lic);

	}
	void setLeafLocation(unsigned int llo)
	{
		if(llo == 0) return;
		fprintf(mFile,"setAttr \".llo\" %i;\n", llo);

	}
	void setLeafDropout(double ldp)
	{
		if(ldp == 0.0) return;
		fprintf(mFile,"setAttr \".ldp\" %f;\n", ldp);

	}
	void setLeafAngle1(double ll1)
	{
		if(ll1 == 75.0) return;
		fprintf(mFile,"setAttr \".ll1\" %f;\n", ll1);

	}
	void setLeafAngle2(double ll2)
	{
		if(ll2 == 25.0) return;
		fprintf(mFile,"setAttr \".ll2\" %f;\n", ll2);

	}
	void setLeafTwist(double ltw)
	{
		if(ltw == 0.0) return;
		fprintf(mFile,"setAttr \".ltw\" %f;\n", ltw);

	}
	void setLeafBend(double lbn)
	{
		if(lbn == 0.0) return;
		fprintf(mFile,"setAttr \".lbn\" %f;\n", lbn);

	}
	void setLeafCurl(size_t lcl_i,const LeafCurl& lcl)
	{
		fprintf(mFile,"setAttr \".lcl[%i]\" ",lcl_i);
		lcl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLeafCurl_Position(size_t lcl_i,float lclp)
	{
		if(lclp == 0.0) return;
		fprintf(mFile,"setAttr \".lcl[%i].lclp\" %f;\n", lcl_i,lclp);

	}
	void setLeafCurl_FloatValue(size_t lcl_i,float lclfv)
	{
		if(lclfv == 0.0) return;
		fprintf(mFile,"setAttr \".lcl[%i].lclfv\" %f;\n", lcl_i,lclfv);

	}
	void setLeafCurl_Interp(size_t lcl_i,unsigned int lcli)
	{
		if(lcli == 0) return;
		fprintf(mFile,"setAttr \".lcl[%i].lcli\" %i;\n", lcl_i,lcli);

	}
	void setLeafTwirl(double ltwl)
	{
		if(ltwl == 0.0) return;
		fprintf(mFile,"setAttr \".ltwl\" %f;\n", ltwl);

	}
	void setLeafSegments(int lsg)
	{
		if(lsg == 5) return;
		fprintf(mFile,"setAttr \".lsg\" %i;\n", lsg);

	}
	void setLeafStart(double lst)
	{
		if(lst == .5) return;
		fprintf(mFile,"setAttr \".lst\" %f;\n", lst);

	}
	void setNumLeafClusters(double nlc)
	{
		if(nlc == 3) return;
		fprintf(mFile,"setAttr \".nlc\" %f;\n", nlc);

	}
	void setLeafFlatness(double lft)
	{
		if(lft == 1.0) return;
		fprintf(mFile,"setAttr \".lft\" %f;\n", lft);

	}
	void setLeafLength(double lln)
	{
		if(lln == 0.3) return;
		fprintf(mFile,"setAttr \".lln\" %f;\n", lln);

	}
	void setLeafBaseWidth(double leb)
	{
		if(leb == 0.15) return;
		fprintf(mFile,"setAttr \".leb\" %f;\n", leb);

	}
	void setLeafTipWidth(double let)
	{
		if(let == 0.05) return;
		fprintf(mFile,"setAttr \".let\" %f;\n", let);

	}
	void setLeafSizeDecay(double lsd)
	{
		if(lsd == 0.7) return;
		fprintf(mFile,"setAttr \".lsd\" %f;\n", lsd);

	}
	void setLeafTranslucence(double ltr)
	{
		if(ltr == 0.7) return;
		fprintf(mFile,"setAttr \".ltr\" %f;\n", ltr);

	}
	void setLeafSpecular(double lsp)
	{
		if(lsp == 0.0) return;
		fprintf(mFile,"setAttr \".lsp\" %f;\n", lsp);

	}
	void setTerminalLeaf(bool tml)
	{
		if(tml == false) return;
		fprintf(mFile,"setAttr \".tml\" %i;\n", tml);

	}
	void setLeafColor1(const float3& lc1)
	{
		fprintf(mFile,"setAttr \".lc1\" -type \"float3\" ");
		lc1.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLeafColor1R(float lr1)
	{
		if(lr1 == 0.2) return;
		fprintf(mFile,"setAttr \".lc1.lr1\" %f;\n", lr1);

	}
	void setLeafColor1G(float lg1)
	{
		if(lg1 == 0.6) return;
		fprintf(mFile,"setAttr \".lc1.lg1\" %f;\n", lg1);

	}
	void setLeafColor1B(float lb1)
	{
		if(lb1 == 0.3) return;
		fprintf(mFile,"setAttr \".lc1.lb1\" %f;\n", lb1);

	}
	void setLeafColor2(const float3& lc2)
	{
		fprintf(mFile,"setAttr \".lc2\" -type \"float3\" ");
		lc2.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLeafColor2R(float lr2)
	{
		if(lr2 == 0.4) return;
		fprintf(mFile,"setAttr \".lc2.lr2\" %f;\n", lr2);

	}
	void setLeafColor2G(float lg2)
	{
		if(lg2 == 0.6) return;
		fprintf(mFile,"setAttr \".lc2.lg2\" %f;\n", lg2);

	}
	void setLeafColor2B(float lb2)
	{
		if(lb2 == 0.3) return;
		fprintf(mFile,"setAttr \".lc2.lb2\" %f;\n", lb2);

	}
	void setLeafHueRand(double lhr)
	{
		if(lhr == 0.0) return;
		fprintf(mFile,"setAttr \".lhr\" %f;\n", lhr);

	}
	void setLeafSatRand(double lsr)
	{
		if(lsr == 0.0) return;
		fprintf(mFile,"setAttr \".lsr\" %f;\n", lsr);

	}
	void setLeafValRand(double lvr)
	{
		if(lvr == 0.0) return;
		fprintf(mFile,"setAttr \".lvr\" %f;\n", lvr);

	}
	void setLeafUseBranchTex(bool lub)
	{
		if(lub == true) return;
		fprintf(mFile,"setAttr \".lub\" %i;\n", lub);

	}
	void setLeafImage(const string& lim)
	{
		if(lim == "NULL") return;
		fprintf(mFile,"setAttr \".lim\" -type \"string\" ");
		lim.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLeafStiffness(double lfs)
	{
		if(lfs == 0.5) return;
		fprintf(mFile,"setAttr \".lfs\" %f;\n", lfs);

	}
	void setBudSize(double bds)
	{
		if(bds == 0.03) return;
		fprintf(mFile,"setAttr \".bds\" %f;\n", bds);

	}
	void setBudColor(const float3& bcr)
	{
		fprintf(mFile,"setAttr \".bcr\" -type \"float3\" ");
		bcr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBudColorR(float bur)
	{
		if(bur == 0.4) return;
		fprintf(mFile,"setAttr \".bcr.bur\" %f;\n", bur);

	}
	void setBudColorG(float bug)
	{
		if(bug == 0.8) return;
		fprintf(mFile,"setAttr \".bcr.bug\" %f;\n", bug);

	}
	void setBudColorB(float bub)
	{
		if(bub == 0.2) return;
		fprintf(mFile,"setAttr \".bcr.bub\" %f;\n", bub);

	}
	void setPetalsInFlower(int pif)
	{
		if(pif == 1) return;
		fprintf(mFile,"setAttr \".pif\" %i;\n", pif);

	}
	void setFlowerLocation(unsigned int flc)
	{
		if(flc == 0) return;
		fprintf(mFile,"setAttr \".flc\" %i;\n", flc);

	}
	void setPetalDropout(double pdp)
	{
		if(pdp == 0.0) return;
		fprintf(mFile,"setAttr \".pdp\" %f;\n", pdp);

	}
	void setFlowerAngle1(double fw1)
	{
		if(fw1 == 75.0) return;
		fprintf(mFile,"setAttr \".fw1\" %f;\n", fw1);

	}
	void setFlowerAngle2(double fw2)
	{
		if(fw2 == 25.0) return;
		fprintf(mFile,"setAttr \".fw2\" %f;\n", fw2);

	}
	void setFlowerTwist(double ftw)
	{
		if(ftw == 0.23) return;
		fprintf(mFile,"setAttr \".ftw\" %f;\n", ftw);

	}
	void setPetalBend(double pbn)
	{
		if(pbn == 0.0) return;
		fprintf(mFile,"setAttr \".pbn\" %f;\n", pbn);

	}
	void setPetalCurl(size_t pcl_i,const PetalCurl& pcl)
	{
		fprintf(mFile,"setAttr \".pcl[%i]\" ",pcl_i);
		pcl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPetalCurl_Position(size_t pcl_i,float pclp)
	{
		if(pclp == 0.0) return;
		fprintf(mFile,"setAttr \".pcl[%i].pclp\" %f;\n", pcl_i,pclp);

	}
	void setPetalCurl_FloatValue(size_t pcl_i,float pclfv)
	{
		if(pclfv == 0.0) return;
		fprintf(mFile,"setAttr \".pcl[%i].pclfv\" %f;\n", pcl_i,pclfv);

	}
	void setPetalCurl_Interp(size_t pcl_i,unsigned int pcli)
	{
		if(pcli == 0) return;
		fprintf(mFile,"setAttr \".pcl[%i].pcli\" %i;\n", pcl_i,pcli);

	}
	void setPetalTwirl(double lpwl)
	{
		if(lpwl == 0.0) return;
		fprintf(mFile,"setAttr \".lpwl\" %f;\n", lpwl);

	}
	void setPetalSegments(int psg)
	{
		if(psg == 5) return;
		fprintf(mFile,"setAttr \".psg\" %i;\n", psg);

	}
	void setFlowerStart(double fst)
	{
		if(fst == 1) return;
		fprintf(mFile,"setAttr \".fst\" %f;\n", fst);

	}
	void setNumFlowers(double nfl)
	{
		if(nfl == 10) return;
		fprintf(mFile,"setAttr \".nfl\" %f;\n", nfl);

	}
	void setPetalFlatness(double pft)
	{
		if(pft == 1.0) return;
		fprintf(mFile,"setAttr \".pft\" %f;\n", pft);

	}
	void setPetalLength(double pln)
	{
		if(pln == 0.2) return;
		fprintf(mFile,"setAttr \".pln\" %f;\n", pln);

	}
	void setPetalBaseWidth(double ptb)
	{
		if(ptb == 0.05) return;
		fprintf(mFile,"setAttr \".ptb\" %f;\n", ptb);

	}
	void setPetalTipWidth(double ptt)
	{
		if(ptt == 0.1) return;
		fprintf(mFile,"setAttr \".ptt\" %f;\n", ptt);

	}
	void setFlowerSizeDecay(double fsd)
	{
		if(fsd == 0.7) return;
		fprintf(mFile,"setAttr \".fsd\" %f;\n", fsd);

	}
	void setFlowerTranslucence(double ftr)
	{
		if(ftr == 0.7) return;
		fprintf(mFile,"setAttr \".ftr\" %f;\n", ftr);

	}
	void setFlowerSpecular(double fsp)
	{
		if(fsp == 0.0) return;
		fprintf(mFile,"setAttr \".fsp\" %f;\n", fsp);

	}
	void setPetalColor1(const float3& pc1)
	{
		fprintf(mFile,"setAttr \".pc1\" -type \"float3\" ");
		pc1.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPetalColor1R(float pr1)
	{
		if(pr1 == 0.8) return;
		fprintf(mFile,"setAttr \".pc1.pr1\" %f;\n", pr1);

	}
	void setPetalColor1G(float pg1)
	{
		if(pg1 == 0.2) return;
		fprintf(mFile,"setAttr \".pc1.pg1\" %f;\n", pg1);

	}
	void setPetalColor1B(float pb1)
	{
		if(pb1 == 0.1) return;
		fprintf(mFile,"setAttr \".pc1.pb1\" %f;\n", pb1);

	}
	void setPetalColor2(const float3& pc2)
	{
		fprintf(mFile,"setAttr \".pc2\" -type \"float3\" ");
		pc2.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPetalColor2R(float pr2)
	{
		if(pr2 == 1.0) return;
		fprintf(mFile,"setAttr \".pc2.pr2\" %f;\n", pr2);

	}
	void setPetalColor2G(float pg2)
	{
		if(pg2 == 1.0) return;
		fprintf(mFile,"setAttr \".pc2.pg2\" %f;\n", pg2);

	}
	void setPetalColor2B(float pb2)
	{
		if(pb2 == 1.0) return;
		fprintf(mFile,"setAttr \".pc2.pb2\" %f;\n", pb2);

	}
	void setFlowerHueRand(double fhr)
	{
		if(fhr == 0.0) return;
		fprintf(mFile,"setAttr \".fhr\" %f;\n", fhr);

	}
	void setFlowerSatRand(double fsr)
	{
		if(fsr == 0.0) return;
		fprintf(mFile,"setAttr \".fsr\" %f;\n", fsr);

	}
	void setFlowerValRand(double fvr)
	{
		if(fvr == 0.0) return;
		fprintf(mFile,"setAttr \".fvr\" %f;\n", fvr);

	}
	void setFlowerUseBranchTex(bool fub)
	{
		if(fub == true) return;
		fprintf(mFile,"setAttr \".fub\" %i;\n", fub);

	}
	void setFlowerImage(const string& fim)
	{
		if(fim == "NULL") return;
		fprintf(mFile,"setAttr \".fim\" -type \"string\" ");
		fim.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFlowerStiffness(double fls)
	{
		if(fls == 0.5) return;
		fprintf(mFile,"setAttr \".fls\" %f;\n", fls);

	}
	void setSimplifyMethod(unsigned int smp)
	{
		if(smp == 0) return;
		fprintf(mFile,"setAttr \".smp\" %i;\n", smp);

	}
	void setColorLengthMap(unsigned int clm)
	{
		if(clm == 0) return;
		fprintf(mFile,"setAttr \".clm\" %i;\n", clm);

	}
	void setTranspLengthMap(unsigned int tlm)
	{
		if(tlm == 0) return;
		fprintf(mFile,"setAttr \".tlm\" %i;\n", tlm);

	}
	void setIncandLengthMap(unsigned int ilm)
	{
		if(ilm == 0) return;
		fprintf(mFile,"setAttr \".ilm\" %i;\n", ilm);

	}
	void setWidthLengthMap(unsigned int wlm)
	{
		if(wlm == 0) return;
		fprintf(mFile,"setAttr \".wlm\" %i;\n", wlm);

	}
	void setSplitLengthMap(unsigned int spl)
	{
		if(spl == 0) return;
		fprintf(mFile,"setAttr \".spl\" %i;\n", spl);

	}
	void setMapColor(bool mcl)
	{
		if(mcl == false) return;
		fprintf(mFile,"setAttr \".mcl\" %i;\n", mcl);

	}
	void setMapOpacity(bool mop)
	{
		if(mop == false) return;
		fprintf(mFile,"setAttr \".mop\" %i;\n", mop);

	}
	void setMapDisplacement(bool mds)
	{
		if(mds == false) return;
		fprintf(mFile,"setAttr \".mds\" %i;\n", mds);

	}
	void setTextureType(unsigned int txt)
	{
		if(txt == 0) return;
		fprintf(mFile,"setAttr \".txt\" %i;\n", txt);

	}
	void setMapMethod(unsigned int mmd)
	{
		if(mmd == 0) return;
		fprintf(mFile,"setAttr \".mmd\" %i;\n", mmd);

	}
	void setTexColorScale(double tcs)
	{
		if(tcs == 1.0) return;
		fprintf(mFile,"setAttr \".tcs\" %f;\n", tcs);

	}
	void setTexColorOffset(double tco)
	{
		if(tco == 0.0) return;
		fprintf(mFile,"setAttr \".tco\" %f;\n", tco);

	}
	void setTexOpacityScale(double tos)
	{
		if(tos == 1.0) return;
		fprintf(mFile,"setAttr \".tos\" %f;\n", tos);

	}
	void setTexOpacityOffset(double too)
	{
		if(too == 0.0) return;
		fprintf(mFile,"setAttr \".too\" %f;\n", too);

	}
	void setDisplacementScale(double dsc)
	{
		if(dsc == 1.0) return;
		fprintf(mFile,"setAttr \".dsc\" %f;\n", dsc);

	}
	void setDisplacementOffset(double dof)
	{
		if(dof == 0.0) return;
		fprintf(mFile,"setAttr \".dof\" %f;\n", dof);

	}
	void setBumpIntensity(double bmi)
	{
		if(bmi == 1.0) return;
		fprintf(mFile,"setAttr \".bmi\" %f;\n", bmi);

	}
	void setBumpBlur(double bbl)
	{
		if(bbl == 0.5) return;
		fprintf(mFile,"setAttr \".bbl\" %f;\n", bbl);

	}
	void setLuminanceIsDisplacement(bool lid)
	{
		if(lid == true) return;
		fprintf(mFile,"setAttr \".lid\" %i;\n", lid);

	}
	void setTexColor1(const float3& tc1)
	{
		fprintf(mFile,"setAttr \".tc1\" -type \"float3\" ");
		tc1.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTexColor1R(float x1r)
	{
		if(x1r == 1.0) return;
		fprintf(mFile,"setAttr \".tc1.x1r\" %f;\n", x1r);

	}
	void setTexColor1G(float x1g)
	{
		if(x1g == 1.0) return;
		fprintf(mFile,"setAttr \".tc1.x1g\" %f;\n", x1g);

	}
	void setTexColor1B(float x1b)
	{
		if(x1b == 1.0) return;
		fprintf(mFile,"setAttr \".tc1.x1b\" %f;\n", x1b);

	}
	void setTexColor2(const float3& tc2)
	{
		fprintf(mFile,"setAttr \".tc2\" -type \"float3\" ");
		tc2.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTexColor2R(float x2r)
	{
		if(x2r == 0.0) return;
		fprintf(mFile,"setAttr \".tc2.x2r\" %f;\n", x2r);

	}
	void setTexColor2G(float x2g)
	{
		if(x2g == 0.0) return;
		fprintf(mFile,"setAttr \".tc2.x2g\" %f;\n", x2g);

	}
	void setTexColor2B(float x2b)
	{
		if(x2b == 0.0) return;
		fprintf(mFile,"setAttr \".tc2.x2b\" %f;\n", x2b);

	}
	void setTexAlpha1(double al1)
	{
		if(al1 == 1.0) return;
		fprintf(mFile,"setAttr \".al1\" %f;\n", al1);

	}
	void setTexAlpha2(double al2)
	{
		if(al2 == 0.0) return;
		fprintf(mFile,"setAttr \".al2\" %f;\n", al2);

	}
	void setTexUniformity(double txu)
	{
		if(txu == 0.5) return;
		fprintf(mFile,"setAttr \".txu\" %f;\n", txu);

	}
	void setFringeRemoval(bool frm)
	{
		if(frm == true) return;
		fprintf(mFile,"setAttr \".frm\" %i;\n", frm);

	}
	void setRepeatU(double rpu)
	{
		if(rpu == 1.0) return;
		fprintf(mFile,"setAttr \".rpu\" %f;\n", rpu);

	}
	void setRepeatV(double rpv)
	{
		if(rpv == 1.0) return;
		fprintf(mFile,"setAttr \".rpv\" %f;\n", rpv);

	}
	void setOffsetU(double ofu)
	{
		if(ofu == 0.0) return;
		fprintf(mFile,"setAttr \".ofu\" %f;\n", ofu);

	}
	void setOffsetV(double ofv)
	{
		if(ofv == 0.0) return;
		fprintf(mFile,"setAttr \".ofv\" %f;\n", ofv);

	}
	void setBlurMult(double bmt)
	{
		if(bmt == 1.0) return;
		fprintf(mFile,"setAttr \".bmt\" %f;\n", bmt);

	}
	void setSmear(double smr)
	{
		if(smr == 0.1) return;
		fprintf(mFile,"setAttr \".smr\" %f;\n", smr);

	}
	void setSmearU(double sru)
	{
		if(sru == 0.0) return;
		fprintf(mFile,"setAttr \".sru\" %f;\n", sru);

	}
	void setSmearV(double srv)
	{
		if(srv == 0.0) return;
		fprintf(mFile,"setAttr \".srv\" %f;\n", srv);

	}
	void setImageName(const string& imn)
	{
		if(imn == "NULL") return;
		fprintf(mFile,"setAttr \".imn\" -type \"string\" ");
		imn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUseFrameExtension(bool ufe)
	{
		if(ufe == false) return;
		fprintf(mFile,"setAttr \".ufe\" %i;\n", ufe);

	}
	void setFrameExtension(int fe)
	{
		if(fe == 1) return;
		fprintf(mFile,"setAttr \".fe\" %i;\n", fe);

	}
	void setFractalRatio(double fra)
	{
		if(fra == 0.7) return;
		fprintf(mFile,"setAttr \".fra\" %f;\n", fra);

	}
	void setFractalAmplitude(double fam)
	{
		if(fam == 1.0) return;
		fprintf(mFile,"setAttr \".fam\" %f;\n", fam);

	}
	void setFractalThreshold(double fth)
	{
		if(fth == 0.0) return;
		fprintf(mFile,"setAttr \".fth\" %f;\n", fth);

	}
	void setMultiStreaks(int mst)
	{
		if(mst == 0) return;
		fprintf(mFile,"setAttr \".mst\" %i;\n", mst);

	}
	void setMultiStreakSpread1(double ms1)
	{
		if(ms1 == 0.2) return;
		fprintf(mFile,"setAttr \".ms1\" %f;\n", ms1);

	}
	void setMultiStreakSpread2(double ms2)
	{
		if(ms2 == 0.2) return;
		fprintf(mFile,"setAttr \".ms2\" %f;\n", ms2);

	}
	void setMultiStreakDiffuseRand(double msdr)
	{
		if(msdr == 0.0) return;
		fprintf(mFile,"setAttr \".msdr\" %f;\n", msdr);

	}
	void setMultiStreakSpecularRand(double mssr)
	{
		if(mssr == 0.0) return;
		fprintf(mFile,"setAttr \".mssr\" %f;\n", mssr);

	}
	void setMultiStreakLightAll(bool msla)
	{
		if(msla == false) return;
		fprintf(mFile,"setAttr \".msla\" %i;\n", msla);

	}
	void setSingleSided(bool snsd)
	{
		if(snsd == false) return;
		fprintf(mFile,"setAttr \".snsd\" %i;\n", snsd);

	}
	void setTubeSections(int tbs)
	{
		if(tbs == 6) return;
		fprintf(mFile,"setAttr \".tbs\" %i;\n", tbs);

	}
	void setSubSegments(int ssg)
	{
		if(ssg == 1) return;
		fprintf(mFile,"setAttr \".ssg\" %i;\n", ssg);

	}
	void setPerPixelLighting(bool ppl)
	{
		if(ppl == false) return;
		fprintf(mFile,"setAttr \".ppl\" %i;\n", ppl);

	}
	void setWidthScale(size_t wsc_i,const WidthScale& wsc)
	{
		fprintf(mFile,"setAttr \".wsc[%i]\" ",wsc_i);
		wsc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWidthScale_Position(size_t wsc_i,float wscp)
	{
		if(wscp == 0.0) return;
		fprintf(mFile,"setAttr \".wsc[%i].wscp\" %f;\n", wsc_i,wscp);

	}
	void setWidthScale_FloatValue(size_t wsc_i,float wscfv)
	{
		if(wscfv == 0.0) return;
		fprintf(mFile,"setAttr \".wsc[%i].wscfv\" %f;\n", wsc_i,wscfv);

	}
	void setWidthScale_Interp(size_t wsc_i,unsigned int wsci)
	{
		if(wsci == 0) return;
		fprintf(mFile,"setAttr \".wsc[%i].wsci\" %i;\n", wsc_i,wsci);

	}
	void setLeafWidthScale(size_t lws_i,const LeafWidthScale& lws)
	{
		fprintf(mFile,"setAttr \".lws[%i]\" ",lws_i);
		lws.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLeafWidthScale_Position(size_t lws_i,float lwsp)
	{
		if(lwsp == 0.0) return;
		fprintf(mFile,"setAttr \".lws[%i].lwsp\" %f;\n", lws_i,lwsp);

	}
	void setLeafWidthScale_FloatValue(size_t lws_i,float lwsfv)
	{
		if(lwsfv == 0.0) return;
		fprintf(mFile,"setAttr \".lws[%i].lwsfv\" %f;\n", lws_i,lwsfv);

	}
	void setLeafWidthScale_Interp(size_t lws_i,unsigned int lwsi)
	{
		if(lwsi == 0) return;
		fprintf(mFile,"setAttr \".lws[%i].lwsi\" %i;\n", lws_i,lwsi);

	}
	void setPetalWidthScale(size_t pws_i,const PetalWidthScale& pws)
	{
		fprintf(mFile,"setAttr \".pws[%i]\" ",pws_i);
		pws.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPetalWidthScale_Position(size_t pws_i,float pwsp)
	{
		if(pwsp == 0.0) return;
		fprintf(mFile,"setAttr \".pws[%i].pwsp\" %f;\n", pws_i,pwsp);

	}
	void setPetalWidthScale_FloatValue(size_t pws_i,float pwsfv)
	{
		if(pwsfv == 0.0) return;
		fprintf(mFile,"setAttr \".pws[%i].pwsfv\" %f;\n", pws_i,pwsfv);

	}
	void setPetalWidthScale_Interp(size_t pws_i,unsigned int pwsi)
	{
		if(pwsi == 0) return;
		fprintf(mFile,"setAttr \".pws[%i].pwsi\" %i;\n", pws_i,pwsi);

	}
	void setTwigLengthScale(size_t tls_i,const TwigLengthScale& tls)
	{
		fprintf(mFile,"setAttr \".tls[%i]\" ",tls_i);
		tls.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTwigLengthScale_Position(size_t tls_i,float tlsp)
	{
		if(tlsp == 0.0) return;
		fprintf(mFile,"setAttr \".tls[%i].tlsp\" %f;\n", tls_i,tlsp);

	}
	void setTwigLengthScale_FloatValue(size_t tls_i,float tlsfv)
	{
		if(tlsfv == 0.0) return;
		fprintf(mFile,"setAttr \".tls[%i].tlsfv\" %f;\n", tls_i,tlsfv);

	}
	void setTwigLengthScale_Interp(size_t tls_i,unsigned int tlsi)
	{
		if(tlsi == 0) return;
		fprintf(mFile,"setAttr \".tls[%i].tlsi\" %i;\n", tls_i,tlsi);

	}
	void setBranchThorns(bool bth)
	{
		if(bth == false) return;
		fprintf(mFile,"setAttr \".bth\" %i;\n", bth);

	}
	void setTwigThorns(bool tth)
	{
		if(tth == false) return;
		fprintf(mFile,"setAttr \".tth\" %i;\n", tth);

	}
	void setLeafThorns(bool lth)
	{
		if(lth == false) return;
		fprintf(mFile,"setAttr \".lth\" %i;\n", lth);

	}
	void setFlowerThorns(bool flt)
	{
		if(flt == false) return;
		fprintf(mFile,"setAttr \".flt\" %i;\n", flt);

	}
	void setThornDensity(double nth)
	{
		if(nth == 10.0) return;
		fprintf(mFile,"setAttr \".nth\" %f;\n", nth);

	}
	void setThornLength(double tln)
	{
		if(tln == 0.5) return;
		fprintf(mFile,"setAttr \".tln\" %f;\n", tln);

	}
	void setThornBaseWidth(double tbwd)
	{
		if(tbwd == 0.05) return;
		fprintf(mFile,"setAttr \".tbwd\" %f;\n", tbwd);

	}
	void setThornTipWidth(double ttwd)
	{
		if(ttwd == 0.01) return;
		fprintf(mFile,"setAttr \".ttwd\" %f;\n", ttwd);

	}
	void setThornElevation(double tel)
	{
		if(tel == 0.6) return;
		fprintf(mFile,"setAttr \".tel\" %f;\n", tel);

	}
	void setThornSpecular(double tsp)
	{
		if(tsp == 0.4) return;
		fprintf(mFile,"setAttr \".tsp\" %f;\n", tsp);

	}
	void setThornBaseColor(const float3& tbc)
	{
		fprintf(mFile,"setAttr \".tbc\" -type \"float3\" ");
		tbc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setThornBaseColorR(float tbcr)
	{
		if(tbcr == 0.5) return;
		fprintf(mFile,"setAttr \".tbc.tbcr\" %f;\n", tbcr);

	}
	void setThornBaseColorG(float tbcg)
	{
		if(tbcg == 0.5) return;
		fprintf(mFile,"setAttr \".tbc.tbcg\" %f;\n", tbcg);

	}
	void setThornBaseColorB(float tbcb)
	{
		if(tbcb == 0.5) return;
		fprintf(mFile,"setAttr \".tbc.tbcb\" %f;\n", tbcb);

	}
	void setThornTipColor(const float3& ttc)
	{
		fprintf(mFile,"setAttr \".ttc\" -type \"float3\" ");
		ttc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setThornTipColorR(float ttcr)
	{
		if(ttcr == 0.5) return;
		fprintf(mFile,"setAttr \".ttc.ttcr\" %f;\n", ttcr);

	}
	void setThornTipColorG(float ttcg)
	{
		if(ttcg == 0.5) return;
		fprintf(mFile,"setAttr \".ttc.ttcg\" %f;\n", ttcg);

	}
	void setThornTipColorB(float ttcb)
	{
		if(ttcb == 0.5) return;
		fprintf(mFile,"setAttr \".ttc.ttcb\" %f;\n", ttcb);

	}
	void setEnvironment(size_t env_i,const Environment& env)
	{
		fprintf(mFile,"setAttr \".env[%i]\" ",env_i);
		env.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEnvironment_Position(size_t env_i,float envp)
	{
		if(envp == 0.0) return;
		fprintf(mFile,"setAttr \".env[%i].envp\" %f;\n", env_i,envp);

	}
	void setEnvironment_Color(size_t env_i,const float3& envc)
	{
		fprintf(mFile,"setAttr \".env[%i].envc\" -type \"float3\" ",env_i);
		envc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEnvironment_ColorR(size_t env_i,float envcr)
	{
		if(envcr == 0.0) return;
		fprintf(mFile,"setAttr \".env[%i].envc.envcr\" %f;\n", env_i,envcr);

	}
	void setEnvironment_ColorG(size_t env_i,float envcg)
	{
		if(envcg == 0.0) return;
		fprintf(mFile,"setAttr \".env[%i].envc.envcg\" %f;\n", env_i,envcg);

	}
	void setEnvironment_ColorB(size_t env_i,float envcb)
	{
		if(envcb == 0.0) return;
		fprintf(mFile,"setAttr \".env[%i].envc.envcb\" %f;\n", env_i,envcb);

	}
	void setEnvironment_Interp(size_t env_i,unsigned int envi)
	{
		if(envi == 0) return;
		fprintf(mFile,"setAttr \".env[%i].envi\" %i;\n", env_i,envi);

	}
	void setReflectionRolloff(size_t rro_i,const ReflectionRolloff& rro)
	{
		fprintf(mFile,"setAttr \".rro[%i]\" ",rro_i);
		rro.write(mFile);
		fprintf(mFile,";\n");

	}
	void setReflectionRolloff_Position(size_t rro_i,float rrop)
	{
		if(rrop == 0.0) return;
		fprintf(mFile,"setAttr \".rro[%i].rrop\" %f;\n", rro_i,rrop);

	}
	void setReflectionRolloff_FloatValue(size_t rro_i,float rrofv)
	{
		if(rrofv == 0.0) return;
		fprintf(mFile,"setAttr \".rro[%i].rrofv\" %f;\n", rro_i,rrofv);

	}
	void setReflectionRolloff_Interp(size_t rro_i,unsigned int rroi)
	{
		if(rroi == 0) return;
		fprintf(mFile,"setAttr \".rro[%i].rroi\" %i;\n", rro_i,rroi);

	}
	void setBranchReflectivity(double brf)
	{
		if(brf == 0.0) return;
		fprintf(mFile,"setAttr \".brf\" %f;\n", brf);

	}
	void setLeafReflectivity(double lrf)
	{
		if(lrf == 0.0) return;
		fprintf(mFile,"setAttr \".lrf\" %f;\n", lrf);

	}
	void setFlowerReflectivity(double frf)
	{
		if(frf == 0.0) return;
		fprintf(mFile,"setAttr \".frf\" %f;\n", frf);

	}
	void setForwardTwist(bool fwt)
	{
		if(fwt == false) return;
		fprintf(mFile,"setAttr \".fwt\" %i;\n", fwt);

	}
	void setLeafForwardTwist(bool lfwt)
	{
		if(lfwt == false) return;
		fprintf(mFile,"setAttr \".lfwt\" %i;\n", lfwt);

	}
	void setPetalForwardTwist(bool lpwt)
	{
		if(lpwt == false) return;
		fprintf(mFile,"setAttr \".lpwt\" %i;\n", lpwt);

	}
	void setEndCaps(bool edc)
	{
		if(edc == false) return;
		fprintf(mFile,"setAttr \".edc\" %i;\n", edc);

	}
	void setHardEdges(bool hde)
	{
		if(hde == false) return;
		fprintf(mFile,"setAttr \".hde\" %i;\n", hde);

	}
	void getOutBrush()
	{
		fprintf(mFile,"\"%s.obr\"",mName.c_str());

	}
	void getTime()
	{
		fprintf(mFile,"\"%s.tim\"",mName.c_str());

	}
	void getGlobalScale()
	{
		fprintf(mFile,"\"%s.gsc\"",mName.c_str());

	}
	void getDepth()
	{
		fprintf(mFile,"\"%s.dep\"",mName.c_str());

	}
	void getModifyDepth()
	{
		fprintf(mFile,"\"%s.mdp\"",mName.c_str());

	}
	void getModifyColor()
	{
		fprintf(mFile,"\"%s.mdc\"",mName.c_str());

	}
	void getModifyAlpha()
	{
		fprintf(mFile,"\"%s.mda\"",mName.c_str());

	}
	void getIlluminated()
	{
		fprintf(mFile,"\"%s.ill\"",mName.c_str());

	}
	void getCastShadows()
	{
		fprintf(mFile,"\"%s.csd\"",mName.c_str());

	}
	void getLightingBasedWidth()
	{
		fprintf(mFile,"\"%s.lbw\"",mName.c_str());

	}
	void getBranches()
	{
		fprintf(mFile,"\"%s.brc\"",mName.c_str());

	}
	void getTwigs()
	{
		fprintf(mFile,"\"%s.twg\"",mName.c_str());

	}
	void getBuds()
	{
		fprintf(mFile,"\"%s.bud\"",mName.c_str());

	}
	void getLeaves()
	{
		fprintf(mFile,"\"%s.lvs\"",mName.c_str());

	}
	void getFlowers()
	{
		fprintf(mFile,"\"%s.flw\"",mName.c_str());

	}
	void getBrushType()
	{
		fprintf(mFile,"\"%s.brt\"",mName.c_str());

	}
	void getBrushWidth()
	{
		fprintf(mFile,"\"%s.bwd\"",mName.c_str());

	}
	void getScreenspaceWidth()
	{
		fprintf(mFile,"\"%s.spw\"",mName.c_str());

	}
	void getDistanceScaling()
	{
		fprintf(mFile,"\"%s.dsl\"",mName.c_str());

	}
	void getMinPixelWidth()
	{
		fprintf(mFile,"\"%s.mpw\"",mName.c_str());

	}
	void getMaxPixelWidth()
	{
		fprintf(mFile,"\"%s.mxp\"",mName.c_str());

	}
	void getStampDensity()
	{
		fprintf(mFile,"\"%s.sdn\"",mName.c_str());

	}
	void getSoftness()
	{
		fprintf(mFile,"\"%s.sft\"",mName.c_str());

	}
	void getEdgeAntialias()
	{
		fprintf(mFile,"\"%s.eaa\"",mName.c_str());

	}
	void getEdgeClip()
	{
		fprintf(mFile,"\"%s.ecl\"",mName.c_str());

	}
	void getEdgeClipDepth()
	{
		fprintf(mFile,"\"%s.ecd\"",mName.c_str());

	}
	void getOcclusionWidthScale()
	{
		fprintf(mFile,"\"%s.ows\"",mName.c_str());

	}
	void getBlurIntensity()
	{
		fprintf(mFile,"\"%s.bin\"",mName.c_str());

	}
	void getColor1()
	{
		fprintf(mFile,"\"%s.cl1\"",mName.c_str());

	}
	void getColor1R()
	{
		fprintf(mFile,"\"%s.cl1.c1r\"",mName.c_str());

	}
	void getColor1G()
	{
		fprintf(mFile,"\"%s.cl1.c1g\"",mName.c_str());

	}
	void getColor1B()
	{
		fprintf(mFile,"\"%s.cl1.c1b\"",mName.c_str());

	}
	void getColor2()
	{
		fprintf(mFile,"\"%s.cl2\"",mName.c_str());

	}
	void getColor2R()
	{
		fprintf(mFile,"\"%s.cl2.c2r\"",mName.c_str());

	}
	void getColor2G()
	{
		fprintf(mFile,"\"%s.cl2.c2g\"",mName.c_str());

	}
	void getColor2B()
	{
		fprintf(mFile,"\"%s.cl2.c2b\"",mName.c_str());

	}
	void getTransparency1()
	{
		fprintf(mFile,"\"%s.tn1\"",mName.c_str());

	}
	void getTransparency1R()
	{
		fprintf(mFile,"\"%s.tn1.t1r\"",mName.c_str());

	}
	void getTransparency1G()
	{
		fprintf(mFile,"\"%s.tn1.t1g\"",mName.c_str());

	}
	void getTransparency1B()
	{
		fprintf(mFile,"\"%s.tn1.t1b\"",mName.c_str());

	}
	void getTransparency2()
	{
		fprintf(mFile,"\"%s.tn2\"",mName.c_str());

	}
	void getTransparency2R()
	{
		fprintf(mFile,"\"%s.tn2.t2r\"",mName.c_str());

	}
	void getTransparency2G()
	{
		fprintf(mFile,"\"%s.tn2.t2g\"",mName.c_str());

	}
	void getTransparency2B()
	{
		fprintf(mFile,"\"%s.tn2.t2b\"",mName.c_str());

	}
	void getIncandescence1()
	{
		fprintf(mFile,"\"%s.in1\"",mName.c_str());

	}
	void getIncandescence1R()
	{
		fprintf(mFile,"\"%s.in1.i1r\"",mName.c_str());

	}
	void getIncandescence1G()
	{
		fprintf(mFile,"\"%s.in1.i1g\"",mName.c_str());

	}
	void getIncandescence1B()
	{
		fprintf(mFile,"\"%s.in1.i1b\"",mName.c_str());

	}
	void getIncandescence2()
	{
		fprintf(mFile,"\"%s.in2\"",mName.c_str());

	}
	void getIncandescence2R()
	{
		fprintf(mFile,"\"%s.in2.i2r\"",mName.c_str());

	}
	void getIncandescence2G()
	{
		fprintf(mFile,"\"%s.in2.i2g\"",mName.c_str());

	}
	void getIncandescence2B()
	{
		fprintf(mFile,"\"%s.in2.i2b\"",mName.c_str());

	}
	void getSpecularColor()
	{
		fprintf(mFile,"\"%s.spc\"",mName.c_str());

	}
	void getSpecularColorR()
	{
		fprintf(mFile,"\"%s.spc.spr\"",mName.c_str());

	}
	void getSpecularColorG()
	{
		fprintf(mFile,"\"%s.spc.spg\"",mName.c_str());

	}
	void getSpecularColorB()
	{
		fprintf(mFile,"\"%s.spc.spb\"",mName.c_str());

	}
	void getSpecular()
	{
		fprintf(mFile,"\"%s.spe\"",mName.c_str());

	}
	void getSpecularPower()
	{
		fprintf(mFile,"\"%s.spp\"",mName.c_str());

	}
	void getTranslucence()
	{
		fprintf(mFile,"\"%s.trn\"",mName.c_str());

	}
	void getGlow()
	{
		fprintf(mFile,"\"%s.glw\"",mName.c_str());

	}
	void getGlowColor()
	{
		fprintf(mFile,"\"%s.glc\"",mName.c_str());

	}
	void getGlowColorR()
	{
		fprintf(mFile,"\"%s.glc.glr\"",mName.c_str());

	}
	void getGlowColorG()
	{
		fprintf(mFile,"\"%s.glc.glg\"",mName.c_str());

	}
	void getGlowColorB()
	{
		fprintf(mFile,"\"%s.glc.glb\"",mName.c_str());

	}
	void getGlowSpread()
	{
		fprintf(mFile,"\"%s.gls\"",mName.c_str());

	}
	void getShaderGlow()
	{
		fprintf(mFile,"\"%s.sgl\"",mName.c_str());

	}
	void getHueRand()
	{
		fprintf(mFile,"\"%s.chr\"",mName.c_str());

	}
	void getSatRand()
	{
		fprintf(mFile,"\"%s.csr\"",mName.c_str());

	}
	void getValRand()
	{
		fprintf(mFile,"\"%s.cvr\"",mName.c_str());

	}
	void getRootFade()
	{
		fprintf(mFile,"\"%s.rfd\"",mName.c_str());

	}
	void getTipFade()
	{
		fprintf(mFile,"\"%s.tfd\"",mName.c_str());

	}
	void getFakeShadow()
	{
		fprintf(mFile,"\"%s.fks\"",mName.c_str());

	}
	void getShadowOffset()
	{
		fprintf(mFile,"\"%s.sof\"",mName.c_str());

	}
	void getShadowDiffusion()
	{
		fprintf(mFile,"\"%s.sdf\"",mName.c_str());

	}
	void getShadowTransparency()
	{
		fprintf(mFile,"\"%s.stn\"",mName.c_str());

	}
	void getBackShadow()
	{
		fprintf(mFile,"\"%s.bks\"",mName.c_str());

	}
	void getBrightnessRand()
	{
		fprintf(mFile,"\"%s.brn\"",mName.c_str());

	}
	void getCenterShadow()
	{
		fprintf(mFile,"\"%s.cns\"",mName.c_str());

	}
	void getDepthShadowType()
	{
		fprintf(mFile,"\"%s.dpt\"",mName.c_str());

	}
	void getDepthShadow()
	{
		fprintf(mFile,"\"%s.dpl\"",mName.c_str());

	}
	void getDepthShadowDepth()
	{
		fprintf(mFile,"\"%s.dps\"",mName.c_str());

	}
	void getRealLights()
	{
		fprintf(mFile,"\"%s.rll\"",mName.c_str());

	}
	void getLightDirection()
	{
		fprintf(mFile,"\"%s.ldr\"",mName.c_str());

	}
	void getLightDirectionX()
	{
		fprintf(mFile,"\"%s.ldr.ldx\"",mName.c_str());

	}
	void getLightDirectionY()
	{
		fprintf(mFile,"\"%s.ldr.ldy\"",mName.c_str());

	}
	void getLightDirectionZ()
	{
		fprintf(mFile,"\"%s.ldr.ldz\"",mName.c_str());

	}
	void getGapSize()
	{
		fprintf(mFile,"\"%s.gsz\"",mName.c_str());

	}
	void getGapSpacing()
	{
		fprintf(mFile,"\"%s.gsp\"",mName.c_str());

	}
	void getGapRand()
	{
		fprintf(mFile,"\"%s.grn\"",mName.c_str());

	}
	void getFlowSpeed()
	{
		fprintf(mFile,"\"%s.fws\"",mName.c_str());

	}
	void getTextureFlow()
	{
		fprintf(mFile,"\"%s.tfl\"",mName.c_str());

	}
	void getTimeClip()
	{
		fprintf(mFile,"\"%s.tcl\"",mName.c_str());

	}
	void getStrokeTime()
	{
		fprintf(mFile,"\"%s.srm\"",mName.c_str());

	}
	void getStartTime()
	{
		fprintf(mFile,"\"%s.sti\"",mName.c_str());

	}
	void getEndTime()
	{
		fprintf(mFile,"\"%s.eti\"",mName.c_str());

	}
	void getTubes()
	{
		fprintf(mFile,"\"%s.tub\"",mName.c_str());

	}
	void getCreationScript()
	{
		fprintf(mFile,"\"%s.csc\"",mName.c_str());

	}
	void getRuntimeScript()
	{
		fprintf(mFile,"\"%s.rsc\"",mName.c_str());

	}
	void getTubeCompletion()
	{
		fprintf(mFile,"\"%s.tcm\"",mName.c_str());

	}
	void getTubesPerStep()
	{
		fprintf(mFile,"\"%s.tps\"",mName.c_str());

	}
	void getTubeRand()
	{
		fprintf(mFile,"\"%s.trd\"",mName.c_str());

	}
	void getStartTubes()
	{
		fprintf(mFile,"\"%s.stb\"",mName.c_str());

	}
	void getLengthMax()
	{
		fprintf(mFile,"\"%s.lnx\"",mName.c_str());

	}
	void getLengthMin()
	{
		fprintf(mFile,"\"%s.lnn\"",mName.c_str());

	}
	void getSegments()
	{
		fprintf(mFile,"\"%s.sgm\"",mName.c_str());

	}
	void getTubeWidth1()
	{
		fprintf(mFile,"\"%s.tw1\"",mName.c_str());

	}
	void getTubeWidth2()
	{
		fprintf(mFile,"\"%s.tw2\"",mName.c_str());

	}
	void getWidthRand()
	{
		fprintf(mFile,"\"%s.wdr\"",mName.c_str());

	}
	void getWidthBias()
	{
		fprintf(mFile,"\"%s.wdb\"",mName.c_str());

	}
	void getLengthFlex()
	{
		fprintf(mFile,"\"%s.lfx\"",mName.c_str());

	}
	void getSegmentLengthBias()
	{
		fprintf(mFile,"\"%s.sgb\"",mName.c_str());

	}
	void getSegmentWidthBias()
	{
		fprintf(mFile,"\"%s.swb\"",mName.c_str());

	}
	void getTubeDirection()
	{
		fprintf(mFile,"\"%s.tdr\"",mName.c_str());

	}
	void getElevationMin()
	{
		fprintf(mFile,"\"%s.elm\"",mName.c_str());

	}
	void getElevationMax()
	{
		fprintf(mFile,"\"%s.elx\"",mName.c_str());

	}
	void getAzimuthMin()
	{
		fprintf(mFile,"\"%s.azn\"",mName.c_str());

	}
	void getAzimuthMax()
	{
		fprintf(mFile,"\"%s.azx\"",mName.c_str());

	}
	void getFlatness1()
	{
		fprintf(mFile,"\"%s.fl1\"",mName.c_str());

	}
	void getFlatness2()
	{
		fprintf(mFile,"\"%s.fl2\"",mName.c_str());

	}
	void getTwist()
	{
		fprintf(mFile,"\"%s.twi\"",mName.c_str());

	}
	void getTwistRate()
	{
		fprintf(mFile,"\"%s.twr\"",mName.c_str());

	}
	void getTwistRand()
	{
		fprintf(mFile,"\"%s.twd\"",mName.c_str());

	}
	void getSpiralMin()
	{
		fprintf(mFile,"\"%s.spm\"",mName.c_str());

	}
	void getSpiralMax()
	{
		fprintf(mFile,"\"%s.spx\"",mName.c_str());

	}
	void getSpiralDecay()
	{
		fprintf(mFile,"\"%s.spd\"",mName.c_str());

	}
	void getBend()
	{
		fprintf(mFile,"\"%s.ben\"",mName.c_str());

	}
	void getBendBias()
	{
		fprintf(mFile,"\"%s.bnb\"",mName.c_str());

	}
	void getDisplacementDelay()
	{
		fprintf(mFile,"\"%s.ddl\"",mName.c_str());

	}
	void getWiggle()
	{
		fprintf(mFile,"\"%s.wgl\"",mName.c_str());

	}
	void getWiggleFrequency()
	{
		fprintf(mFile,"\"%s.wgf\"",mName.c_str());

	}
	void getWiggleOffset()
	{
		fprintf(mFile,"\"%s.wgo\"",mName.c_str());

	}
	void getCurl()
	{
		fprintf(mFile,"\"%s.crl\"",mName.c_str());

	}
	void getCurlFrequency()
	{
		fprintf(mFile,"\"%s.crf\"",mName.c_str());

	}
	void getCurlOffset()
	{
		fprintf(mFile,"\"%s.cro\"",mName.c_str());

	}
	void getNoise()
	{
		fprintf(mFile,"\"%s.noi\"",mName.c_str());

	}
	void getNoiseFrequency()
	{
		fprintf(mFile,"\"%s.nof\"",mName.c_str());

	}
	void getNoiseOffset()
	{
		fprintf(mFile,"\"%s.noo\"",mName.c_str());

	}
	void getSplitMaxDepth()
	{
		fprintf(mFile,"\"%s.smd\"",mName.c_str());

	}
	void getSplitRand()
	{
		fprintf(mFile,"\"%s.srd\"",mName.c_str());

	}
	void getSplitAngle()
	{
		fprintf(mFile,"\"%s.spa\"",mName.c_str());

	}
	void getSplitSizeDecay()
	{
		fprintf(mFile,"\"%s.ssd\"",mName.c_str());

	}
	void getSplitBias()
	{
		fprintf(mFile,"\"%s.slb\"",mName.c_str());

	}
	void getSplitTwist()
	{
		fprintf(mFile,"\"%s.slt\"",mName.c_str());

	}
	void getStartBranches()
	{
		fprintf(mFile,"\"%s.sbr\"",mName.c_str());

	}
	void getNumBranches()
	{
		fprintf(mFile,"\"%s.nbr\"",mName.c_str());

	}
	void getBranchDropout()
	{
		fprintf(mFile,"\"%s.bdr\"",mName.c_str());

	}
	void getMiddleBranch()
	{
		fprintf(mFile,"\"%s.mbr\"",mName.c_str());

	}
	void getMinSize()
	{
		fprintf(mFile,"\"%s.mms\"",mName.c_str());

	}
	void getPathFollow()
	{
		fprintf(mFile,"\"%s.pfl\"",mName.c_str());

	}
	void getPathAttract()
	{
		fprintf(mFile,"\"%s.pat\"",mName.c_str());

	}
	void getCurveFollow()
	{
		fprintf(mFile,"\"%s.cfw\"",mName.c_str());

	}
	void getCurveAttract()
	{
		fprintf(mFile,"\"%s.cva\"",mName.c_str());

	}
	void getCurveMaxDist()
	{
		fprintf(mFile,"\"%s.cmd\"",mName.c_str());

	}
	void getUniformForce()
	{
		fprintf(mFile,"\"%s.ufr\"",mName.c_str());

	}
	void getUniformForceX()
	{
		fprintf(mFile,"\"%s.ufr.ufx\"",mName.c_str());

	}
	void getUniformForceY()
	{
		fprintf(mFile,"\"%s.ufr.ufy\"",mName.c_str());

	}
	void getUniformForceZ()
	{
		fprintf(mFile,"\"%s.ufr.ufz\"",mName.c_str());

	}
	void getTurbulenceType()
	{
		fprintf(mFile,"\"%s.trt\"",mName.c_str());

	}
	void getTurbulenceInterpolation()
	{
		fprintf(mFile,"\"%s.tin\"",mName.c_str());

	}
	void getTurbulence()
	{
		fprintf(mFile,"\"%s.tur\"",mName.c_str());

	}
	void getTurbulenceFrequency()
	{
		fprintf(mFile,"\"%s.trf\"",mName.c_str());

	}
	void getTurbulenceSpeed()
	{
		fprintf(mFile,"\"%s.trs\"",mName.c_str());

	}
	void getTurbulenceOffset()
	{
		fprintf(mFile,"\"%s.tro\"",mName.c_str());

	}
	void getTurbulenceOffsetX()
	{
		fprintf(mFile,"\"%s.tro.trx\"",mName.c_str());

	}
	void getTurbulenceOffsetY()
	{
		fprintf(mFile,"\"%s.tro.try\"",mName.c_str());

	}
	void getTurbulenceOffsetZ()
	{
		fprintf(mFile,"\"%s.tro.trz\"",mName.c_str());

	}
	void getRandom()
	{
		fprintf(mFile,"\"%s.ran\"",mName.c_str());

	}
	void getGravity()
	{
		fprintf(mFile,"\"%s.grv\"",mName.c_str());

	}
	void getMomentum()
	{
		fprintf(mFile,"\"%s.mmt\"",mName.c_str());

	}
	void getDeflection()
	{
		fprintf(mFile,"\"%s.def\"",mName.c_str());

	}
	void getDeflectionMin()
	{
		fprintf(mFile,"\"%s.dfm\"",mName.c_str());

	}
	void getDeflectionMax()
	{
		fprintf(mFile,"\"%s.dfx\"",mName.c_str());

	}
	void getTwigsInCluster()
	{
		fprintf(mFile,"\"%s.tic\"",mName.c_str());

	}
	void getTwigDropout()
	{
		fprintf(mFile,"\"%s.tdp\"",mName.c_str());

	}
	void getTwigAngle1()
	{
		fprintf(mFile,"\"%s.ta1\"",mName.c_str());

	}
	void getTwigAngle2()
	{
		fprintf(mFile,"\"%s.ta2\"",mName.c_str());

	}
	void getTwigTwist()
	{
		fprintf(mFile,"\"%s.ttw\"",mName.c_str());

	}
	void getTwigLength()
	{
		fprintf(mFile,"\"%s.twl\"",mName.c_str());

	}
	void getTwigStart()
	{
		fprintf(mFile,"\"%s.tst\"",mName.c_str());

	}
	void getNumTwigClusters()
	{
		fprintf(mFile,"\"%s.ntc\"",mName.c_str());

	}
	void getTwigBaseWidth()
	{
		fprintf(mFile,"\"%s.twb\"",mName.c_str());

	}
	void getTwigTipWidth()
	{
		fprintf(mFile,"\"%s.twt\"",mName.c_str());

	}
	void getTwigStiffness()
	{
		fprintf(mFile,"\"%s.tgs\"",mName.c_str());

	}
	void getBranchAfterTwigs()
	{
		fprintf(mFile,"\"%s.bat\"",mName.c_str());

	}
	void getLeavesInCluster()
	{
		fprintf(mFile,"\"%s.lic\"",mName.c_str());

	}
	void getLeafLocation()
	{
		fprintf(mFile,"\"%s.llo\"",mName.c_str());

	}
	void getLeafDropout()
	{
		fprintf(mFile,"\"%s.ldp\"",mName.c_str());

	}
	void getLeafAngle1()
	{
		fprintf(mFile,"\"%s.ll1\"",mName.c_str());

	}
	void getLeafAngle2()
	{
		fprintf(mFile,"\"%s.ll2\"",mName.c_str());

	}
	void getLeafTwist()
	{
		fprintf(mFile,"\"%s.ltw\"",mName.c_str());

	}
	void getLeafBend()
	{
		fprintf(mFile,"\"%s.lbn\"",mName.c_str());

	}
	void getLeafCurl(size_t lcl_i)
	{
		fprintf(mFile,"\"%s.lcl[%i]\"",mName.c_str(),lcl_i);

	}
	void getLeafCurl_Position(size_t lcl_i)
	{
		fprintf(mFile,"\"%s.lcl[%i].lclp\"",mName.c_str(),lcl_i);

	}
	void getLeafCurl_FloatValue(size_t lcl_i)
	{
		fprintf(mFile,"\"%s.lcl[%i].lclfv\"",mName.c_str(),lcl_i);

	}
	void getLeafCurl_Interp(size_t lcl_i)
	{
		fprintf(mFile,"\"%s.lcl[%i].lcli\"",mName.c_str(),lcl_i);

	}
	void getLeafTwirl()
	{
		fprintf(mFile,"\"%s.ltwl\"",mName.c_str());

	}
	void getLeafSegments()
	{
		fprintf(mFile,"\"%s.lsg\"",mName.c_str());

	}
	void getLeafStart()
	{
		fprintf(mFile,"\"%s.lst\"",mName.c_str());

	}
	void getNumLeafClusters()
	{
		fprintf(mFile,"\"%s.nlc\"",mName.c_str());

	}
	void getLeafFlatness()
	{
		fprintf(mFile,"\"%s.lft\"",mName.c_str());

	}
	void getLeafLength()
	{
		fprintf(mFile,"\"%s.lln\"",mName.c_str());

	}
	void getLeafBaseWidth()
	{
		fprintf(mFile,"\"%s.leb\"",mName.c_str());

	}
	void getLeafTipWidth()
	{
		fprintf(mFile,"\"%s.let\"",mName.c_str());

	}
	void getLeafSizeDecay()
	{
		fprintf(mFile,"\"%s.lsd\"",mName.c_str());

	}
	void getLeafTranslucence()
	{
		fprintf(mFile,"\"%s.ltr\"",mName.c_str());

	}
	void getLeafSpecular()
	{
		fprintf(mFile,"\"%s.lsp\"",mName.c_str());

	}
	void getTerminalLeaf()
	{
		fprintf(mFile,"\"%s.tml\"",mName.c_str());

	}
	void getLeafColor1()
	{
		fprintf(mFile,"\"%s.lc1\"",mName.c_str());

	}
	void getLeafColor1R()
	{
		fprintf(mFile,"\"%s.lc1.lr1\"",mName.c_str());

	}
	void getLeafColor1G()
	{
		fprintf(mFile,"\"%s.lc1.lg1\"",mName.c_str());

	}
	void getLeafColor1B()
	{
		fprintf(mFile,"\"%s.lc1.lb1\"",mName.c_str());

	}
	void getLeafColor2()
	{
		fprintf(mFile,"\"%s.lc2\"",mName.c_str());

	}
	void getLeafColor2R()
	{
		fprintf(mFile,"\"%s.lc2.lr2\"",mName.c_str());

	}
	void getLeafColor2G()
	{
		fprintf(mFile,"\"%s.lc2.lg2\"",mName.c_str());

	}
	void getLeafColor2B()
	{
		fprintf(mFile,"\"%s.lc2.lb2\"",mName.c_str());

	}
	void getLeafHueRand()
	{
		fprintf(mFile,"\"%s.lhr\"",mName.c_str());

	}
	void getLeafSatRand()
	{
		fprintf(mFile,"\"%s.lsr\"",mName.c_str());

	}
	void getLeafValRand()
	{
		fprintf(mFile,"\"%s.lvr\"",mName.c_str());

	}
	void getLeafUseBranchTex()
	{
		fprintf(mFile,"\"%s.lub\"",mName.c_str());

	}
	void getLeafImage()
	{
		fprintf(mFile,"\"%s.lim\"",mName.c_str());

	}
	void getLeafStiffness()
	{
		fprintf(mFile,"\"%s.lfs\"",mName.c_str());

	}
	void getBudSize()
	{
		fprintf(mFile,"\"%s.bds\"",mName.c_str());

	}
	void getBudColor()
	{
		fprintf(mFile,"\"%s.bcr\"",mName.c_str());

	}
	void getBudColorR()
	{
		fprintf(mFile,"\"%s.bcr.bur\"",mName.c_str());

	}
	void getBudColorG()
	{
		fprintf(mFile,"\"%s.bcr.bug\"",mName.c_str());

	}
	void getBudColorB()
	{
		fprintf(mFile,"\"%s.bcr.bub\"",mName.c_str());

	}
	void getPetalsInFlower()
	{
		fprintf(mFile,"\"%s.pif\"",mName.c_str());

	}
	void getFlowerLocation()
	{
		fprintf(mFile,"\"%s.flc\"",mName.c_str());

	}
	void getPetalDropout()
	{
		fprintf(mFile,"\"%s.pdp\"",mName.c_str());

	}
	void getFlowerAngle1()
	{
		fprintf(mFile,"\"%s.fw1\"",mName.c_str());

	}
	void getFlowerAngle2()
	{
		fprintf(mFile,"\"%s.fw2\"",mName.c_str());

	}
	void getFlowerTwist()
	{
		fprintf(mFile,"\"%s.ftw\"",mName.c_str());

	}
	void getPetalBend()
	{
		fprintf(mFile,"\"%s.pbn\"",mName.c_str());

	}
	void getPetalCurl(size_t pcl_i)
	{
		fprintf(mFile,"\"%s.pcl[%i]\"",mName.c_str(),pcl_i);

	}
	void getPetalCurl_Position(size_t pcl_i)
	{
		fprintf(mFile,"\"%s.pcl[%i].pclp\"",mName.c_str(),pcl_i);

	}
	void getPetalCurl_FloatValue(size_t pcl_i)
	{
		fprintf(mFile,"\"%s.pcl[%i].pclfv\"",mName.c_str(),pcl_i);

	}
	void getPetalCurl_Interp(size_t pcl_i)
	{
		fprintf(mFile,"\"%s.pcl[%i].pcli\"",mName.c_str(),pcl_i);

	}
	void getPetalTwirl()
	{
		fprintf(mFile,"\"%s.lpwl\"",mName.c_str());

	}
	void getPetalSegments()
	{
		fprintf(mFile,"\"%s.psg\"",mName.c_str());

	}
	void getFlowerStart()
	{
		fprintf(mFile,"\"%s.fst\"",mName.c_str());

	}
	void getNumFlowers()
	{
		fprintf(mFile,"\"%s.nfl\"",mName.c_str());

	}
	void getPetalFlatness()
	{
		fprintf(mFile,"\"%s.pft\"",mName.c_str());

	}
	void getPetalLength()
	{
		fprintf(mFile,"\"%s.pln\"",mName.c_str());

	}
	void getPetalBaseWidth()
	{
		fprintf(mFile,"\"%s.ptb\"",mName.c_str());

	}
	void getPetalTipWidth()
	{
		fprintf(mFile,"\"%s.ptt\"",mName.c_str());

	}
	void getFlowerSizeDecay()
	{
		fprintf(mFile,"\"%s.fsd\"",mName.c_str());

	}
	void getFlowerTranslucence()
	{
		fprintf(mFile,"\"%s.ftr\"",mName.c_str());

	}
	void getFlowerSpecular()
	{
		fprintf(mFile,"\"%s.fsp\"",mName.c_str());

	}
	void getPetalColor1()
	{
		fprintf(mFile,"\"%s.pc1\"",mName.c_str());

	}
	void getPetalColor1R()
	{
		fprintf(mFile,"\"%s.pc1.pr1\"",mName.c_str());

	}
	void getPetalColor1G()
	{
		fprintf(mFile,"\"%s.pc1.pg1\"",mName.c_str());

	}
	void getPetalColor1B()
	{
		fprintf(mFile,"\"%s.pc1.pb1\"",mName.c_str());

	}
	void getPetalColor2()
	{
		fprintf(mFile,"\"%s.pc2\"",mName.c_str());

	}
	void getPetalColor2R()
	{
		fprintf(mFile,"\"%s.pc2.pr2\"",mName.c_str());

	}
	void getPetalColor2G()
	{
		fprintf(mFile,"\"%s.pc2.pg2\"",mName.c_str());

	}
	void getPetalColor2B()
	{
		fprintf(mFile,"\"%s.pc2.pb2\"",mName.c_str());

	}
	void getFlowerHueRand()
	{
		fprintf(mFile,"\"%s.fhr\"",mName.c_str());

	}
	void getFlowerSatRand()
	{
		fprintf(mFile,"\"%s.fsr\"",mName.c_str());

	}
	void getFlowerValRand()
	{
		fprintf(mFile,"\"%s.fvr\"",mName.c_str());

	}
	void getFlowerUseBranchTex()
	{
		fprintf(mFile,"\"%s.fub\"",mName.c_str());

	}
	void getFlowerImage()
	{
		fprintf(mFile,"\"%s.fim\"",mName.c_str());

	}
	void getFlowerStiffness()
	{
		fprintf(mFile,"\"%s.fls\"",mName.c_str());

	}
	void getSimplifyMethod()
	{
		fprintf(mFile,"\"%s.smp\"",mName.c_str());

	}
	void getColorLengthMap()
	{
		fprintf(mFile,"\"%s.clm\"",mName.c_str());

	}
	void getTranspLengthMap()
	{
		fprintf(mFile,"\"%s.tlm\"",mName.c_str());

	}
	void getIncandLengthMap()
	{
		fprintf(mFile,"\"%s.ilm\"",mName.c_str());

	}
	void getWidthLengthMap()
	{
		fprintf(mFile,"\"%s.wlm\"",mName.c_str());

	}
	void getSplitLengthMap()
	{
		fprintf(mFile,"\"%s.spl\"",mName.c_str());

	}
	void getMapColor()
	{
		fprintf(mFile,"\"%s.mcl\"",mName.c_str());

	}
	void getMapOpacity()
	{
		fprintf(mFile,"\"%s.mop\"",mName.c_str());

	}
	void getMapDisplacement()
	{
		fprintf(mFile,"\"%s.mds\"",mName.c_str());

	}
	void getTextureType()
	{
		fprintf(mFile,"\"%s.txt\"",mName.c_str());

	}
	void getMapMethod()
	{
		fprintf(mFile,"\"%s.mmd\"",mName.c_str());

	}
	void getTexColorScale()
	{
		fprintf(mFile,"\"%s.tcs\"",mName.c_str());

	}
	void getTexColorOffset()
	{
		fprintf(mFile,"\"%s.tco\"",mName.c_str());

	}
	void getTexOpacityScale()
	{
		fprintf(mFile,"\"%s.tos\"",mName.c_str());

	}
	void getTexOpacityOffset()
	{
		fprintf(mFile,"\"%s.too\"",mName.c_str());

	}
	void getDisplacementScale()
	{
		fprintf(mFile,"\"%s.dsc\"",mName.c_str());

	}
	void getDisplacementOffset()
	{
		fprintf(mFile,"\"%s.dof\"",mName.c_str());

	}
	void getBumpIntensity()
	{
		fprintf(mFile,"\"%s.bmi\"",mName.c_str());

	}
	void getBumpBlur()
	{
		fprintf(mFile,"\"%s.bbl\"",mName.c_str());

	}
	void getLuminanceIsDisplacement()
	{
		fprintf(mFile,"\"%s.lid\"",mName.c_str());

	}
	void getTexColor1()
	{
		fprintf(mFile,"\"%s.tc1\"",mName.c_str());

	}
	void getTexColor1R()
	{
		fprintf(mFile,"\"%s.tc1.x1r\"",mName.c_str());

	}
	void getTexColor1G()
	{
		fprintf(mFile,"\"%s.tc1.x1g\"",mName.c_str());

	}
	void getTexColor1B()
	{
		fprintf(mFile,"\"%s.tc1.x1b\"",mName.c_str());

	}
	void getTexColor2()
	{
		fprintf(mFile,"\"%s.tc2\"",mName.c_str());

	}
	void getTexColor2R()
	{
		fprintf(mFile,"\"%s.tc2.x2r\"",mName.c_str());

	}
	void getTexColor2G()
	{
		fprintf(mFile,"\"%s.tc2.x2g\"",mName.c_str());

	}
	void getTexColor2B()
	{
		fprintf(mFile,"\"%s.tc2.x2b\"",mName.c_str());

	}
	void getTexAlpha1()
	{
		fprintf(mFile,"\"%s.al1\"",mName.c_str());

	}
	void getTexAlpha2()
	{
		fprintf(mFile,"\"%s.al2\"",mName.c_str());

	}
	void getTexUniformity()
	{
		fprintf(mFile,"\"%s.txu\"",mName.c_str());

	}
	void getFringeRemoval()
	{
		fprintf(mFile,"\"%s.frm\"",mName.c_str());

	}
	void getRepeatU()
	{
		fprintf(mFile,"\"%s.rpu\"",mName.c_str());

	}
	void getRepeatV()
	{
		fprintf(mFile,"\"%s.rpv\"",mName.c_str());

	}
	void getOffsetU()
	{
		fprintf(mFile,"\"%s.ofu\"",mName.c_str());

	}
	void getOffsetV()
	{
		fprintf(mFile,"\"%s.ofv\"",mName.c_str());

	}
	void getBlurMult()
	{
		fprintf(mFile,"\"%s.bmt\"",mName.c_str());

	}
	void getSmear()
	{
		fprintf(mFile,"\"%s.smr\"",mName.c_str());

	}
	void getSmearU()
	{
		fprintf(mFile,"\"%s.sru\"",mName.c_str());

	}
	void getSmearV()
	{
		fprintf(mFile,"\"%s.srv\"",mName.c_str());

	}
	void getImageName()
	{
		fprintf(mFile,"\"%s.imn\"",mName.c_str());

	}
	void getUseFrameExtension()
	{
		fprintf(mFile,"\"%s.ufe\"",mName.c_str());

	}
	void getFrameExtension()
	{
		fprintf(mFile,"\"%s.fe\"",mName.c_str());

	}
	void getFractalRatio()
	{
		fprintf(mFile,"\"%s.fra\"",mName.c_str());

	}
	void getFractalAmplitude()
	{
		fprintf(mFile,"\"%s.fam\"",mName.c_str());

	}
	void getFractalThreshold()
	{
		fprintf(mFile,"\"%s.fth\"",mName.c_str());

	}
	void getMultiStreaks()
	{
		fprintf(mFile,"\"%s.mst\"",mName.c_str());

	}
	void getMultiStreakSpread1()
	{
		fprintf(mFile,"\"%s.ms1\"",mName.c_str());

	}
	void getMultiStreakSpread2()
	{
		fprintf(mFile,"\"%s.ms2\"",mName.c_str());

	}
	void getMultiStreakDiffuseRand()
	{
		fprintf(mFile,"\"%s.msdr\"",mName.c_str());

	}
	void getMultiStreakSpecularRand()
	{
		fprintf(mFile,"\"%s.mssr\"",mName.c_str());

	}
	void getMultiStreakLightAll()
	{
		fprintf(mFile,"\"%s.msla\"",mName.c_str());

	}
	void getSingleSided()
	{
		fprintf(mFile,"\"%s.snsd\"",mName.c_str());

	}
	void getTubeSections()
	{
		fprintf(mFile,"\"%s.tbs\"",mName.c_str());

	}
	void getSubSegments()
	{
		fprintf(mFile,"\"%s.ssg\"",mName.c_str());

	}
	void getPerPixelLighting()
	{
		fprintf(mFile,"\"%s.ppl\"",mName.c_str());

	}
	void getWidthScale(size_t wsc_i)
	{
		fprintf(mFile,"\"%s.wsc[%i]\"",mName.c_str(),wsc_i);

	}
	void getWidthScale_Position(size_t wsc_i)
	{
		fprintf(mFile,"\"%s.wsc[%i].wscp\"",mName.c_str(),wsc_i);

	}
	void getWidthScale_FloatValue(size_t wsc_i)
	{
		fprintf(mFile,"\"%s.wsc[%i].wscfv\"",mName.c_str(),wsc_i);

	}
	void getWidthScale_Interp(size_t wsc_i)
	{
		fprintf(mFile,"\"%s.wsc[%i].wsci\"",mName.c_str(),wsc_i);

	}
	void getLeafWidthScale(size_t lws_i)
	{
		fprintf(mFile,"\"%s.lws[%i]\"",mName.c_str(),lws_i);

	}
	void getLeafWidthScale_Position(size_t lws_i)
	{
		fprintf(mFile,"\"%s.lws[%i].lwsp\"",mName.c_str(),lws_i);

	}
	void getLeafWidthScale_FloatValue(size_t lws_i)
	{
		fprintf(mFile,"\"%s.lws[%i].lwsfv\"",mName.c_str(),lws_i);

	}
	void getLeafWidthScale_Interp(size_t lws_i)
	{
		fprintf(mFile,"\"%s.lws[%i].lwsi\"",mName.c_str(),lws_i);

	}
	void getPetalWidthScale(size_t pws_i)
	{
		fprintf(mFile,"\"%s.pws[%i]\"",mName.c_str(),pws_i);

	}
	void getPetalWidthScale_Position(size_t pws_i)
	{
		fprintf(mFile,"\"%s.pws[%i].pwsp\"",mName.c_str(),pws_i);

	}
	void getPetalWidthScale_FloatValue(size_t pws_i)
	{
		fprintf(mFile,"\"%s.pws[%i].pwsfv\"",mName.c_str(),pws_i);

	}
	void getPetalWidthScale_Interp(size_t pws_i)
	{
		fprintf(mFile,"\"%s.pws[%i].pwsi\"",mName.c_str(),pws_i);

	}
	void getTwigLengthScale(size_t tls_i)
	{
		fprintf(mFile,"\"%s.tls[%i]\"",mName.c_str(),tls_i);

	}
	void getTwigLengthScale_Position(size_t tls_i)
	{
		fprintf(mFile,"\"%s.tls[%i].tlsp\"",mName.c_str(),tls_i);

	}
	void getTwigLengthScale_FloatValue(size_t tls_i)
	{
		fprintf(mFile,"\"%s.tls[%i].tlsfv\"",mName.c_str(),tls_i);

	}
	void getTwigLengthScale_Interp(size_t tls_i)
	{
		fprintf(mFile,"\"%s.tls[%i].tlsi\"",mName.c_str(),tls_i);

	}
	void getBranchThorns()
	{
		fprintf(mFile,"\"%s.bth\"",mName.c_str());

	}
	void getTwigThorns()
	{
		fprintf(mFile,"\"%s.tth\"",mName.c_str());

	}
	void getLeafThorns()
	{
		fprintf(mFile,"\"%s.lth\"",mName.c_str());

	}
	void getFlowerThorns()
	{
		fprintf(mFile,"\"%s.flt\"",mName.c_str());

	}
	void getThornDensity()
	{
		fprintf(mFile,"\"%s.nth\"",mName.c_str());

	}
	void getThornLength()
	{
		fprintf(mFile,"\"%s.tln\"",mName.c_str());

	}
	void getThornBaseWidth()
	{
		fprintf(mFile,"\"%s.tbwd\"",mName.c_str());

	}
	void getThornTipWidth()
	{
		fprintf(mFile,"\"%s.ttwd\"",mName.c_str());

	}
	void getThornElevation()
	{
		fprintf(mFile,"\"%s.tel\"",mName.c_str());

	}
	void getThornSpecular()
	{
		fprintf(mFile,"\"%s.tsp\"",mName.c_str());

	}
	void getThornBaseColor()
	{
		fprintf(mFile,"\"%s.tbc\"",mName.c_str());

	}
	void getThornBaseColorR()
	{
		fprintf(mFile,"\"%s.tbc.tbcr\"",mName.c_str());

	}
	void getThornBaseColorG()
	{
		fprintf(mFile,"\"%s.tbc.tbcg\"",mName.c_str());

	}
	void getThornBaseColorB()
	{
		fprintf(mFile,"\"%s.tbc.tbcb\"",mName.c_str());

	}
	void getThornTipColor()
	{
		fprintf(mFile,"\"%s.ttc\"",mName.c_str());

	}
	void getThornTipColorR()
	{
		fprintf(mFile,"\"%s.ttc.ttcr\"",mName.c_str());

	}
	void getThornTipColorG()
	{
		fprintf(mFile,"\"%s.ttc.ttcg\"",mName.c_str());

	}
	void getThornTipColorB()
	{
		fprintf(mFile,"\"%s.ttc.ttcb\"",mName.c_str());

	}
	void getEnvironment(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i]\"",mName.c_str(),env_i);

	}
	void getEnvironment_Position(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envp\"",mName.c_str(),env_i);

	}
	void getEnvironment_Color(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envc\"",mName.c_str(),env_i);

	}
	void getEnvironment_ColorR(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envc.envcr\"",mName.c_str(),env_i);

	}
	void getEnvironment_ColorG(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envc.envcg\"",mName.c_str(),env_i);

	}
	void getEnvironment_ColorB(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envc.envcb\"",mName.c_str(),env_i);

	}
	void getEnvironment_Interp(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envi\"",mName.c_str(),env_i);

	}
	void getReflectionRolloff(size_t rro_i)
	{
		fprintf(mFile,"\"%s.rro[%i]\"",mName.c_str(),rro_i);

	}
	void getReflectionRolloff_Position(size_t rro_i)
	{
		fprintf(mFile,"\"%s.rro[%i].rrop\"",mName.c_str(),rro_i);

	}
	void getReflectionRolloff_FloatValue(size_t rro_i)
	{
		fprintf(mFile,"\"%s.rro[%i].rrofv\"",mName.c_str(),rro_i);

	}
	void getReflectionRolloff_Interp(size_t rro_i)
	{
		fprintf(mFile,"\"%s.rro[%i].rroi\"",mName.c_str(),rro_i);

	}
	void getBranchReflectivity()
	{
		fprintf(mFile,"\"%s.brf\"",mName.c_str());

	}
	void getLeafReflectivity()
	{
		fprintf(mFile,"\"%s.lrf\"",mName.c_str());

	}
	void getFlowerReflectivity()
	{
		fprintf(mFile,"\"%s.frf\"",mName.c_str());

	}
	void getForwardTwist()
	{
		fprintf(mFile,"\"%s.fwt\"",mName.c_str());

	}
	void getLeafForwardTwist()
	{
		fprintf(mFile,"\"%s.lfwt\"",mName.c_str());

	}
	void getPetalForwardTwist()
	{
		fprintf(mFile,"\"%s.lpwt\"",mName.c_str());

	}
	void getEndCaps()
	{
		fprintf(mFile,"\"%s.edc\"",mName.c_str());

	}
	void getHardEdges()
	{
		fprintf(mFile,"\"%s.hde\"",mName.c_str());

	}
protected:
	Brush(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_BRUSH_H__