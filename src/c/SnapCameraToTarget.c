#include "funcs.h"
#include "globals.h"
#include "sdata.h"
#include "vecmath.h"

SDATA(g_nCameraLosClear, 4);

/* Seat the camera on its eye (0x80034c84, 100 bytes): copies the eye
   (g_anCameraPos + 0xC) into the smoothed position, zeros the spring tracking
   state, raises g_nCameraSnapped + g_nCameraLosClear and rebases the
   camera-to-target angles. Its callers step the springs first, so the eye
   moves continuously; the camera reset is ResetCameraStateToTarget. */
void SnapCameraToTarget(void) {
  CopyVector(g_anCameraPos, g_anCameraPos + 3); /* g_anCameraEyeTarget */
  g_nCameraCollisionRetries = 0;
  g_nCameraStuckFrames = 0;
  g_nCameraSnapped = 1;
  g_nCameraLosClear = 1;
  g_nCameraTargetInverted = ComputeCameraToTargetAngle(g_anCameraPos);
}
