#ifndef _PORTALS_H_
#define _PORTALS_H_

#include "basictypes.h"
#include "v_video.h"
#include "r_defs.h"
#include "actor.h"
#include "p_local.h"
#include "m_bbox.h"

void P_SpawnLinePortal(line_t* line);


/* code ported from prototype */
bool P_ClipLineToPortal(line_t* line, line_t* portal, fixed_t viewx, fixed_t viewy, bool partial = true, bool samebehind = true);
void P_TranslatePortalXY(line_t* src, line_t* dst, fixed_t& x, fixed_t& y);
void P_TranslatePortalVXVY(line_t* src, line_t* dst, fixed_t& vx, fixed_t& vy);
void P_TranslatePortalAngle(line_t* src, line_t* dst, angle_t& angle);
void P_TranslatePortalZ(line_t* src, line_t* dst, fixed_t& z);
void P_NormalizeVXVY(fixed_t& vx, fixed_t& vy);

// basically, this is a teleporting tracer function,
// which can be used by itself (to calculate portal-aware offsets, say, for projectiles)
// or to teleport normal tracers (like hitscan, railgun, autoaim tracers)
class PortalTracer
{
public:
	PortalTracer(fixed_t startx, fixed_t starty, fixed_t endx, fixed_t endy);

	// trace to next portal
	bool TraceStep();
	// trace to last available portal on the path
	void TraceAll() { while (TraceStep()) continue; }

	int depth;
	fixed_t startx;
	fixed_t starty;
	fixed_t intx;
	fixed_t inty;
	fixed_t intxIn;
	fixed_t intyIn;
	fixed_t endx;
	fixed_t endy;
	angle_t angle;
	fixed_t z;
	fixed_t frac;
	line_t* in;
	line_t* out;
	fixed_t vx;
	fixed_t vy;
};

/* new code */
fixed_t P_PointLineDistance(line_t* line, fixed_t x, fixed_t y);

#endif