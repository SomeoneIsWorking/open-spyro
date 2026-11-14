# Our names (SCUS_942.28)

Names the psx-spyro port uses for this executable where they differ from or go beyond this tree's own.
The symbol map (`config/symbol_addrs.txt`) keeps the tree's names; ours enter it only where the tree has none. "Port file" is a psx-spyro path.

## Names that differ

| address | this tree | psx-spyro | port file | meaning |
|---|---|---|---|---|
| `0x800113A0` | `g_pSharedLoadBuffer` | `CdLoadMode` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x8001157C` | `switchdataD_8001157c` | `FirstVolumeTable` | `titles/spyro1/core/audio/native_spu_common_attr.cpp` | The two retail switch tables the argument's two preset indices index, one case arm per entry: `sll $v0, $v1, 2 ; lui $at, 0x8001 ; addu $at, $at, $v0 ; lw $v0, 0x157c($at)` for the first pair and `0x159c` for the second. Both are read at ru |
| `0x8001159C` | `switchdataD_8001159c` | `SecondVolumeTable` | `titles/spyro1/core/audio/native_spu_common_attr.cpp` |  |
| `0x80012604` | `ResetLevelState` | `ResetSavedState` | `titles/spyro1/core/execution/native_level_initialization.cpp` | `jal` at 0x800127A8 |
| `0x800133E0` | `RelocateActorMeshHeader` | `PatchMobyModelPointers` | `titles/spyro1/core/moby/native_shared_models.cpp` | `jal` at 0x8005B890 |
| `0x80014564` | `TickCutsceneBundleLoadStream` | `LoadCutscene` | `titles/spyro1/core/hud/native_pause_menu.cpp` | `jal` at 0x8002E338 |
| `0x80015370` | `TickLevelTransitionStream` | `LoadLevel` | `titles/spyro1/core/frame/transition_skip.cpp` |  |
| `0x80016500` | `CdReadSyncSectors` | `CdLoadSync` | `titles/spyro1/core/hud/native_pause_menu.cpp` | `jal` at 0x8002E328 |
| `0x80016784` | `LinkOTPrimitives` | `FlattenBins` | `titles/spyro1/core/frame/draw_section.cpp` | func_80016784(0x800): links the bins into one chain and returns its head, DrawOTag's argument. |
| `0x800168DC` | `AddPrimToOT` | `OverlayLinkEntry` | `titles/spyro1/core/execution/native_util.cpp` | 0x800168DC, the overlay pair's link (render/overlay_pair.h). |
| `0x80016914` | `FillWord` | `GuestFunctionsFill` | `titles/spyro1/core/guest_functions.h` | word fill |
| `0x80016AB4` | `ArcTan2` | `GuestFunctionsAtan2` | `titles/spyro1/core/guest_functions.h` |  |
| `0x80016C58` | `LookupSine` | `NativeCameraSine` | `titles/spyro1/core/camera/native_camera.cpp` | `jal` at 0x80034280 and 0x800342B8 |
| `0x80016CB0` | `LookupCosine` | `NativeCameraCosine` | `titles/spyro1/core/camera/native_camera.cpp` | `jal` at 0x80034228 and 0x80034238 |
| `0x80016D2C` | `ApplyEulerRotation` | `MatrixFromAngles` | `titles/spyro1/core/player/native_player_physics.cpp` | The guest callees the two bodies below call, each named by the `jal` that reaches it. A callee is a code address, so it is the 26-bit field of that instruction rather than a `lui`+immediate pair, and an address audit re-derives it from the  |
| `0x80017048` | `RotateVectorByMatrix` | `NativeEffectStateRotate` | `titles/spyro1/core/effect/native_effect_state.cpp` | The callees, each named by the `jal` at the call site the comment gives. A callee is the 26-bit field of that instruction rather than a `lui`+immediate pair, and the address audit re-derives it from the `jal` itself. The first seven are own |
| `0x800170C0` | `ApplyActiveGteRotation` | `RotateLast` | `titles/spyro1/core/effect/native_effect_state.cpp` | VecRotateByLastMatrix |
| `0x800171FC` | `VectorLength` | `GuestFunctionsVecLen` | `titles/spyro1/core/guest_functions.h` |  |
| `0x8001729C` | `RefineSqrtEstimate` | `VecRefineMagnitude` | `titles/spyro1/core/camera/native_camera.cpp` | The guest helpers the collision body calls, named for what the decompilation's own listing says each one does (external/spyro-1/asm/math.s, asm/collision.s and src/camera.c). They are `jal` targets rather than the `lui`-plus-immediate data  |
| `0x800175B8` | `ScaleVector3ByRatio` | `VecScaleToLength` | `titles/spyro1/core/camera/native_camera.cpp` | `jal` at 0x80033E80 |
| `0x800176C8` | `RShiftVector3` | `GuestFunctionsVsra` | `titles/spyro1/core/guest_functions.h` | arithmetic shift of a vector |
| `0x800176F0` | `ZeroVector` | `GuestFunctionsZero3` | `titles/spyro1/core/guest_functions.h` | three-word vector clear |
| `0x80017700` | `CopyVector` | `GuestFunctionsCopy3` | `titles/spyro1/core/guest_functions.h` | three-word vector copy |
| `0x80017758` | `AddVector` | `GuestFunctionsVadd` | `titles/spyro1/core/guest_functions.h` |  |
| `0x8001778C` | `SubtractVector` | `GuestFunctionsVsub` | `titles/spyro1/core/guest_functions.h` |  |
| `0x80017908` | `AbsAngleDelta8` | `AngDiff8` | `titles/spyro1/core/guest_functions.h` |  |
| `0x800179F0` | `ApproachAngle8` | `AdvanceAnimationFrame` | `titles/spyro1/core/moby/native_moby_animation.cpp` | The frame an animation reaches from frame a1 by a2, with a3 the wrap threshold; a leaf. `jal` at 0x80038F70 and 0x80038F94 |
| `0x80017AA4` | `ProjectWorldPointGTEUnscaled` | `RotateVectorByCamera` | `titles/spyro1/core/camera/native_camera.cpp` | `jal` at 0x80034B94 |
| `0x80017E98` | `ConvertRGB15ToLuma8` | `GreyConversion` | `titles/spyro1/render/pause_backdrop.cpp` |  |
| `0x80018908` | `DrawDemoModeOverlay` | `DrawDemoText` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x800189F0` | `DrawMotionTrailRibbons` | `DrawHud` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x80018F30` | `DrawCinematicLetterbox` | `DrawBorder` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x800190D4` | `DrawFullscreenTint` | `DrawFade` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x8001919C` | `EmitTexturedQuad` | `TexturedQuad` | `titles/spyro1/render/hud_anchor.h` |  |
| `0x80019300` | `EnqueueHudSprites` | `DrawCollectables` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x8001A050` | `LevelTransition_Draw` | `LevelTransitionDraw` | `titles/spyro1/core/frame/draw_section.cpp` | GS_LevelTransition and GS_ArrivalCamera: tally, Spyro and the sky join at its DrawSync, 0x8001A334. |
| `0x8001A40C` | `PauseMenu_Draw` | `MenuDraw` | `titles/spyro1/core/frame/draw_section.cpp` | func_8001A40C, the menus: D_800758B8 counts its draws; the first stores the scene greyed into VRAM, every later one opens with PutDrawEnv, which the real frame applied, and ends with DrawOTag(func_80016784(0)) at 0x8001C598. |
| `0x8001C694` | `MenuTransition_Draw` | `ExitLevelDraw` | `titles/spyro1/core/frame/draw_section.cpp` | GS_ExitLevel: pass 0 opens with PutDrawEnv, LoadImage and DrawSync, pass 1 with the fog store and PutDrawEnv; both reach LinkOTPrimitives at 0x8001C96C before DrawOTag. |
| `0x8001CFDC` | `DragonRescue_Draw` | `DragonDraw` | `titles/spyro1/core/frame/draw_section.cpp` | func_8001CFDC, GS_Dragon: every m_State's drawers, fade and border join at its DrawSync, 0x8001D644. |
| `0x8001D718` | `SaveLoadMenu_Draw` | `FairyDraw` | `titles/spyro1/core/frame/draw_section.cpp` | func_8001D718, GS_Fairy: its drawers, menu text and border end at its DrawSync, 0x8001E168. |
| `0x8001E24C` | `ActorCutscene_Draw` | `BalloonistDraw` | `titles/spyro1/core/frame/draw_section.cpp` | func_8001E24C, GS_Balloonist: its dialogue, mobys and border end at its DrawSync, 0x8001E5E4. |
| `0x8001ED5C` | `GamestateDraw` | `FrameDraw` | `titles/spyro1/core/frame/frame_draw.cpp` | Called by main 0x80012204 at 0x8001227C; it returns past that jal's delay slot. |
| `0x8001F158` | `BuildActorDrawList` | `PrimaryListPassEntry` | `titles/spyro1/render/actor_list.h` |  |
| `0x8001F798` | `EmitActorDrawList` | `RegularEmitterEntry` | `titles/spyro1/render/actor_emitter_passes.h` |  |
| `0x800208FC` | `BuildSecondaryActorDrawList` | `SecondaryListPassEntry` | `titles/spyro1/render/actor_list.h` |  |
| `0x80020F34` | `EmitSecondaryActorPrimitives` | `LitEmitterEntry` | `titles/spyro1/render/actor_emitter_passes.h` |  |
| `0x80022A2C` | `RasterizeSpritePrimQueue` | `SpriteQueueEntry` | `titles/spyro1/render/sprite_queue.h` |  |
| `0x80023AC4` | `RasterizeSpyroModel` | `PairedActorEntry` | `titles/spyro1/render/paired_actor.h` |  |
| `0x800258F0` | `RenderWorldChunks` | `SharedFactsEntry` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8002BBE0` | `TickCdMusicStream` | `CdMusicUpdate` | `titles/spyro1/core/hud/native_pause_menu.cpp` | `jal` at 0x8002E340 |
| `0x8002C534` | `ExitPauseMenuToGame` | `ResumeFromPause` | `titles/spyro1/core/hud/native_pause_menu.cpp` | `jal` at 0x8002E9F0 |
| `0x8002C618` | `BeginPauseToMenuTransition` | `ExitLevel` | `titles/spyro1/core/hud/native_pause_menu.cpp` | `jal` at 0x8002EB0C |
| `0x8002C664` | `BeginWorldHubReturn` | `ReturnHome` | `titles/spyro1/core/frame/transition_skip.cpp` |  |
| `0x8002C714` | `EnterInventoryMenu` | `OpenInventory` | `titles/spyro1/core/hud/native_pause_menu.cpp` | `jal` at 0x8002EA34 |
| `0x8002D170` | `BeginStoryIntro` | `KickTitleScreen` | `titles/spyro1/core/hud/native_pause_menu.cpp` | `jal` at 0x8002E368 |
| `0x8002D338` | `BeginCutscene` | `StartCutscenePlayback` | `titles/spyro1/core/hud/native_pause_menu.cpp` | `jal` at 0x8002E360 |
| `0x8002D810` | `ApplyCheatCodeEffect` | `CheatApplyEffect` | `titles/spyro1/core/guest_functions.h` | CheatApplyEffect (cheats.c) |
| `0x8003385C` | `GamestateUpdate` | `FrameUpdate` | `titles/spyro1/core/frame/frame_driver.cpp` |  |
| `0x80033C50` | `BuildCameraViewMatrix` | `CameraUpdateMatrices` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x80033E40` | `CheckLineOfSightSegment` | `RayBetweenPointsIsClear` | `titles/spyro1/core/camera/native_camera.cpp` | `jal` at 0x8003475C |
| `0x80033F08` | `ComputeCameraToTargetAngle` | `UpdateSphericalCoords` | `titles/spyro1/core/camera/native_camera.cpp` | `jal` at 0x80034440 |
| `0x80034198` | `LoadCameraTargetAnglesFromMode` | `ApplySphericalPreset` | `titles/spyro1/core/camera/native_camera.cpp` | `jal` at 0x80034364 |
| `0x80034204` | `ComputeCameraOrbitOffset` | `SphericalToCartesian` | `titles/spyro1/core/camera/native_camera.cpp` | `jal` at 0x80034414 |
| `0x800342F8` | `UpdateCameraEulerAngles` | `CameraRotationFromSphere` | `titles/spyro1/core/camera/native_camera.cpp` | `jal` at 0x80034450 |
| `0x80034358` | `ResetCameraStateToTarget` | `ResetCameraToSphericalPreset` | `titles/spyro1/core/camera/native_camera.cpp` | `jal` at 0x800347E4 |
| `0x8003D194` | `TickSpyroAnimStateMachine` | `ResetObjectMotion` | `titles/spyro1/core/player/native_player_physics.cpp` | `jal` at 0x8004A918 |
| `0x8003EA68` | `ChangeSpyroState` | `SetPlayerState` | `titles/spyro1/core/player/native_player_physics.cpp` | `jal` at 0x8004A834 |
| `0x80043FE4` | `IntegrateSpyroMotionForSubstep` | `InitLevelObject` | `titles/spyro1/core/player/native_player_physics.cpp` | `jal` at 0x8004A87C |
| `0x8004888C` | `AdvanceSpyroSubstepState` | `ResetObjectState` | `titles/spyro1/core/player/native_player_physics.cpp` | `jal` at 0x8004A8E4 |
| `0x80049660` | `TickSpyroAnimLayer1` | `InitObjectPath` | `titles/spyro1/core/player/native_player_physics.cpp` | `jal` at 0x8004A928 |
| `0x80049880` | `SmoothSpyroByteEulerSpring` | `SmoothHeadLook` | `titles/spyro1/core/effect/native_effect_state.cpp` |  |
| `0x800499C0` | `TickSpyroFlameAttack` | `UpdateFlameBurst` | `titles/spyro1/core/effect/native_effect_state.cpp` | The two registered entries, named so the guest call sites inside the bodies can be spelled as offsets from them. A `jal`/`jalr` returns to its own pc + 8, and callGuestNow returns through the $ra its caller left, so a callee that keeps a fr |
| `0x80049DFC` | `AdvanceSpyroAnimLayer2Frame` | `AdvanceTailAnimationFrames` | `titles/spyro1/core/player/native_player_animation.cpp` | 0x80049DFC, the tail stepper's own callee, from the `jal` at 0x80049F24. |
| `0x80049E8C` | `TickSpyroAnimLayer2` | `InitObjectTrailing` | `titles/spyro1/core/player/native_player_physics.cpp` | `jal` at 0x8004A938 |
| `0x80049F3C` | `TickSpyroAnimLayer2GateTimer` | `UpdateFlameTailLock` | `titles/spyro1/core/player/native_player_physics.cpp` | `jal` at 0x8004A930 |
| `0x80049FAC` | `SampleSpyroShadowRingHeights` | `UpdateGroundShadow` | `titles/spyro1/core/effect/native_effect_state.cpp` |  |
| `0x8004AC24` | `ResetSpyroEntity` | `ResetSpyro` | `titles/spyro1/core/frame/draw_cuts.cpp` |  |
| `0x8004AE38` | `CastRayWorldAndActors` | `SegmentHitsWorld` | `titles/spyro1/core/camera/native_camera.cpp` | `jal` at 0x80033EB8 |
| `0x8004BE4C` | `CollideSphereWithWorldAndActors` | `SphereCollisionCheck` | `titles/spyro1/core/camera/native_camera.cpp` | `jal` at 0x80034604 |
| `0x8004D5EC` | `FindGroundHeightBelow` | `SurfaceProbe` | `titles/spyro1/core/effect/native_effect_state.cpp` | func_8004D5EC |
| `0x8004EBA8` | `EmitSkyMesh` | `SkyEntry` | `titles/spyro1/render/sky.h` |  |
| `0x80050BD0` | `DrawPortalsAndSky` | `PortalsEntry` | `titles/spyro1/render/portals.h` |  |
| `0x800521C0` | `BuildRenderEntityLists` | `QueueMobys` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x800536A4` | `ResetPadFrameSubstepTable` | `PadReset` | `titles/spyro1/core/input/native_gamepad.cpp` | Memcpy(dst, src, len), the `jal` at 0x80053738. Already owned natively as the `copyw` override at 0x80016958, so this call lands in that owner rather than in the JIT. PadReset(pad), the `jal` at 0x80053740 in gamepad.c's pad-buffer swap. No |
| `0x80053708` | `MovePadInputState` | `ResetObjectLists` | `titles/spyro1/core/player/native_player_physics.cpp` | `jal` at 0x8004A814 |
| `0x800542E4` | `SetHudCounterDigits` | `StepCounter` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x80054400` | `OffsetHudIconRollAxis` | `NativeHudCollectablesPlayId` | `titles/spyro1/core/hud/native_hud_collectables.cpp` | Guest helpers, each a `jal` operand of the body. |
| `0x8005445C` | `OffsetHudDigitRollAxis` | `NativeHudCollectablesFadeId` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x800544A8` | `CommitHudCounterAnimState` | `SetSubState` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x80054988` | `UpdateHudCounters` | `HudTick` | `titles/spyro1/core/hud/native_pause_menu.cpp` | Guest callees, each named by its `jal` site. `jal` at 0x8002E148 |
| `0x80055A78` | `PlaySoundEffect` | `PlaySound` | `titles/spyro1/core/audio/native_moby_sound.cpp` | Start one sound, 3D (flag 8) or 2D, on a named channel. `jal` at 0x8003859C |
| `0x800562A4` | `StopSoundVoicesByOwner` | `StopMobySounds` | `titles/spyro1/core/audio/native_moby_sound.cpp` | Stop the sounds a moby owns (native_sound_position owns that entry). `jal` at 0x8003856C |
| `0x80056B28` | `StopAllSoundExceptMask` | `KillSoundsAndMusic` | `titles/spyro1/core/hud/native_pause_menu.cpp` | `jal` at 0x8002E27C |
| `0x80056C84` | `ComputeVoicePanAndFalloff` | `PositionalStereoVolume` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x80056DC4` | `GetSoundVoiceStatusByOwner` | `ProbeActiveSound` | `titles/spyro1/core/audio/native_sound_position.cpp` | The guest callees, each named by the `jal` at the call site the comment gives. A callee is the 26-bit field of that instruction rather than a `lui`+immediate pair, and an address audit re-derives it from the `jal` itself. |
| `0x80056ED4` | `TickSpuPerFrame` | `SpuUpdate` | `titles/spyro1/core/hud/native_pause_menu.cpp` | `jal` at 0x8002E2A0 |
| `0x800573C8` | `RasterizeEmitList` | `ParticlesEntry` | `titles/spyro1/render/particles.h` | RasterizeEmitList. |
| `0x800580F4` | `DrawWorldSparkleParticles` | `EmittersEntry` | `titles/spyro1/render/glows.h` |  |
| `0x800584C4` | `DrawWorldRotatingBillboards` | `SparklesEntry` | `titles/spyro1/render/glows.h` |  |
| `0x80058864` | `DrawDragonRescueAuraStar` | `RescueStarEntry` | `titles/spyro1/render/rescue_star.h` |  |
| `0x80058CC0` | `RotateLightVectorXZ` | `SpecularUpdate` | `titles/spyro1/core/hud/native_pause_menu.cpp` | `jal` at 0x8002E18C |
| `0x80058D64` | `DrawSpyroFlameTrails` | `FlameEntry` | `titles/spyro1/render/flame.h` |  |
| `0x80059A48` | `DrawSpyroDropShadow` | `DropShadowEntry` | `titles/spyro1/render/drop_shadow.h` |  |
| `0x80059F8C` | `DrawActorDropShadows` | `MobyShadowsEntry` | `titles/spyro1/render/moby_shadows.h` |  |
| `0x8005B6F8` | `InitActorMeshScratchRegions` | `AllocateBuffers` | `titles/spyro1/core/moby/native_shared_models.cpp` | `jal` at 0x8005B8B8 |
| `0x8005B8E0` | `start` | `Crt0Entry` | `titles/spyro1/core/runtime/runtime.cpp` |  |
| `0x8005B988` | `__main` | `StaticConstructors` | `titles/spyro1/core/frame/frame_driver.cpp` |  |
| `0x8005C7AC` | `ApplySpuVoiceAttr` | `MarkSlotsChanged` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x8005CC58` | `SetSpuCommonAttr` | `SpuSetCommonAttr` | `titles/spyro1/core/hud/native_pause_menu.cpp` | `jal` at 0x8002E6C4 |
| `0x8005CFEC` | `ApplySpuVoiceAttrRange` | `VoiceAttrFieldWriter` | `titles/spyro1/core/audio/native_spu_voice_attributes.cpp` | The library's own voice-attribute field writer, the target of the body's only `jal`. It bounds both index arguments against 0x18, so 0x17 = 23 is the last field index it accepts. `jal` at 0x8005C7BC |
| `0x8005DBC4` | `VSync` | `RuntimeVSync` | `titles/spyro1/core/runtime/runtime.cpp` | VSync's negative-argument path reads D_800749E0 (asm/psyq.s:2646-2649), the vblank counter this title's field clock advances. |
| `0x8005DE28` | `DmaCallback` | `CallbackDispatch` | `titles/spyro1/core/audio/native_spu_callbacks.cpp` | 0x8005DE28 — the library's callback dispatcher, the target of the `jal` at 0x8005C794. It reads the hook entry out of the table at D_8007498C and calls it with the class and the caller's pointer. |
| `0x80062090` | `ResetGpuTimeoutDeadline` | `LibgpuTimeoutArm` | `titles/spyro1/core/runtime/runtime.cpp` |  |
| `0x800620C4` | `CheckGpuTimeout` | `LibgpuTimeoutCheck` | `titles/spyro1/core/runtime/runtime.cpp` |  |
| `0x800623D8` | `MulMatrix0` | `MultiplyMatrices` | `titles/spyro1/core/player/native_player_physics.cpp` | `jal` at 0x8004A9CC |
| `0x80062618` | `SetGeomOffset` | `LibgteSetGeomOffset` | `titles/spyro1/core/runtime/runtime.cpp` | SetGeomOffset (ctc2 $a0,$24 at 0x80062620) and SetGeomScreen (ctc2 $a0,$26 at 0x80062638). |
| `0x80062638` | `SetGeomScreen` | `LibgteSetGeomScreen` | `titles/spyro1/core/runtime/runtime.cpp` |  |
| `0x8006272C` | `GetRandomU32` | `GuestFunctionsRand` | `titles/spyro1/core/guest_functions.h` |  |
| `0x80063C48` | `CdControl` | `LibcdControl` | `titles/spyro1/core/runtime/runtime.cpp` |  |
| `0x80063D80` | `CdControlForce` | `LibcdControlFire` | `titles/spyro1/core/runtime/runtime.cpp` |  |
| `0x80063EAC` | `CdControlBlocking` | `LibcdControlBlocking` | `titles/spyro1/core/runtime/runtime.cpp` |  |
| `0x80063FF0` | `CdMix` | `NativePauseMenuCdMix` | `titles/spyro1/core/hud/native_pause_menu.cpp` | `jal` at 0x8002E778 |
| `0x800647A0` | `CdSync` | `LibcdSync` | `titles/spyro1/core/runtime/runtime.cpp` |  |
| `0x80064CEC` | `CdCommandSync` | `LibcdCommand` | `titles/spyro1/core/runtime/runtime.cpp` | From external/spyro-1's labels in asm/psyq.s. CdControlF takes (com, param) only: its a2 is the caller's leftover register, so it binds the entry that writes no result buffer. |
| `0x800653B4` | `CdInitDriver` | `CdInitHandshake` | `titles/spyro1/core/runtime/runtime.cpp` |  |
| `0x8006BC84` | `g_abSpyroStateTransitionAnimMatrix` | `StatePairTable` | `titles/spyro1/core/player/native_player_animation.cpp` | [lastAnimationState][state] (u8) |
| `0x8006C470` | `g_abSpyroStateAnimIndexMap` | `StateDefaultAnimation` | `titles/spyro1/core/effect/native_effect_state.cpp` | spyro_StateDefaultAnimation |
| `0x8006C4A0` | `g_abSpyroAnimDescTable` | `SpyroAnimations` | `titles/spyro1/core/frame/draw_motion.cpp` | Spyro's animation table: four bytes per animation, its loop start then its end; 0x8003CB24 steps a part's next frame past the end back to the start. |
| `0x8006C714` | `g_anSpyroWallNudgeAngleByProbeMask` | `ProbeMaskTable` | `titles/spyro1/core/player/native_player_physics.cpp` |  |
| `0x8006C82C` | `g_anCameraEscapeOffsets` | `RowAngleOffsets` | `titles/spyro1/core/camera/native_camera.cpp` | D_8006C82C[5][3] |
| `0x8006CAB4` | `g_anCameraStuckReseatParams` | `SphericalPresets` | `titles/spyro1/core/camera/native_camera.cpp` | D_8006CAB4[5] |
| `0x8006CB8C` | `g_anFogFullScreenTriPairSxy` | `ScreenTriangles` | `titles/spyro1/render/portals.cpp` | D_8006CB8C: the two triangles that cover the screen, three packed points each. |
| `0x8006CBF8` | `g_anSineLut` | `SinTable` | `titles/spyro1/core/guest_globals.h` | D_8006CBF8: the sine table indexed with a 12-bit angle; cosine reads it a quarter turn on. |
| `0x8006CF48` | `g_apWorldChunkQuadCornerVertPtrs` | `FactsCoarseQuadCells` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8006CF58` | `g_apWorldChunkSubQuadVertPtrs` | `FactsFineQuadPieces` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8006CF98` | `g_anWorldChunkQuadSubdiv2EdgeTris` | `FactsCoarseQuadCracks` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8006CFC8` | `g_anWorldChunkQuadSubdiv4TriRecords` | `FactsFineQuadCracks` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8006D058` | `g_anWorldChunkQuadUvOrientPairs` | `FactsPageRemaps` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8006D0D8` | `g_apWorldChunkQuadCenterVertPtrs` | `FactsFineInnerPoints` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8006D0E8` | `g_anWorldChunkTriangleSubdiv2Tris` | `FactsCoarseTriangleCells` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8006D0F8` | `g_anWorldChunkTriangleSubdiv4Tris` | `FactsFineTrianglePieces` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8006D138` | `g_anWorldChunkTriangleSubdiv2EdgeTriRecords` | `FactsCoarseTriangleCracks` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8006D1C8` | `g_anWorldChunkTriangleSubdiv4EdgeTriRecords` | `FactsFineTriangleCracks` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8006D378` | `g_abWorldChunkTriangleSubdiv2UvRotIdx` | `FactsCoarseTriangleSubTexture` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8006D388` | `g_abWorldChunkTriangleSubdiv4UvRotIdx` | `FactsFineTriangleSubTexture` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8006D3C8` | `g_anWorldChunkTriangleUvOrientPairs` | `FactsTriangleUvs` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8006D5C8` | `g_anWorldChunkTriList6Vert` | `SharedFactsTrianglePieces` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8006D5E4` | `g_anWorldChunkTriList9Vert` | `SharedFactsQuadPieces` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x8006D614` | `g_anAnimRootMotionDeltaLut` | `VertexDeltas` | `titles/spyro1/render/actor_facts.h` | 128 packed delta words |
| `0x8006D808` | `g_abArcSinLut` | `ArcSine` | `titles/spyro1/render/lit_actor_emitter.cpp` | 0x8006D808: signed bytes, the reflection's v by the clamped vertical ratio. |
| `0x8006D908` | `g_abArcTanOctantLut` | `ArcTangent` | `titles/spyro1/render/lit_actor_emitter.cpp` | 0x8006D908: the angle in 1/512 turns, to 0x40, of a ratio min * 64 / max. |
| `0x8006D94C` | `g_anSpyroFlameAgeConfigShort` | `AgeConfig` | `titles/spyro1/render/flame.h` | A part's descriptor per length: start entry << 24, ribbon steps << 16, grey ramp << 8 (+0x80 for parts 4..7). |
| `0x8006DAA8` | `g_anSpyroFlameArcPathsShort` | `ArcPaths` | `titles/spyro1/render/flame.h` | The arc entries, 0x10 bytes each: parts 0..3 0xC0 bytes apart, parts 4..7 0x100 apart from +0x300. |
| `0x8006E1A8` | `g_anSpyroFlameCapColors` | `CapColours` | `titles/spyro1/render/flame.h` | The tip's four colour words, +0x10 when superflame. |
| `0x8006E238` | `g_anSpyroFlameTipOffsets` | `BurstVectors` | `titles/spyro1/core/effect/native_effect_state.cpp` | D_8006E238, four 12-byte local offsets |
| `0x8006E268` | `g_anSpyroShadowCircleTable` | `DropShadowRing` | `titles/spyro1/render/drop_shadow.h` | The ring's sine/cosine pairs, one word per point (80059DDC). |
| `0x8006E2A8` | `g_anSpyroShadowProbeOffsetTable` | `ShadowFanOffsets` | `titles/spyro1/core/effect/native_effect_state.cpp` | D_8006E2A8, the ring's eight fan offsets |
| `0x8006E77C` | `g_anHudRollInStepTable` | `SparkIds` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x8006E798` | `g_anHudRollOutStepTable` | `FadeIds` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x8006E7B4` | `g_abHudButterflyRingXY` | `SpriteValueBytes` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x8006E9A4` | `g_anLevelDeathPlaneZTable` | `HeightThresholdTable` | `titles/spyro1/core/effect/native_effect_state.cpp` | D_8006E9A4, one word per level |
| `0x8006F3C0` | `g_anDragonRescueScaleCurve` | `ShrinkTable` | `titles/spyro1/core/frame/dragon_shrink.cpp` | D_8006F3C0: 24 halfword factors, one a tick. |
| `0x8006F414` | `g_abLevelTotalDragonsTable` | `LevelDragonTotals` | `titles/spyro1/core/guest_globals.h` |  |
| `0x8006F438` | `g_anLevelTotalGemsTable` | `GemCollectTarget` | `titles/spyro1/core/hud/native_hud_collectables.cpp` | 0x80054C68 `lh $v1,-0xbc8($at)`: the level's gem target the tally must match. |
| `0x8006F7D0` | `g_apWorldNames` | `TitleCardNames` | `titles/spyro1/core/guest_globals.h` | external/open-spyro names: g_apTitleCardNames per homeworld (1..6), g_apLevelNameStrings at (id / 10 - 1) * 6 + id % 10 ("HOME" for a homeworld), g_abLevelTotalDragonsTable at the same index. |
| `0x8006F7F0` | `g_apLevelNameStrings` | `LevelNames` | `titles/spyro1/core/guest_globals.h` |  |
| `0x8006FA74` | `g_abTitleSlideInCurve` | `TitlescreenAnimIn` | `titles/spyro1/core/guest_globals.h` | g_TitlescreenAnimIn |
| `0x8006FA84` | `g_abTitleSlideOutCurve` | `TitlescreenAnimOut` | `titles/spyro1/core/guest_globals.h` | g_TitlescreenAnimOut |
| `0x8006FCF4` | `g_apMainDrawEntityList` | `RenderQueue` | `titles/spyro1/core/moby/native_moby_lists.cpp` |  |
| `0x800712F4` | `g_anActorDrawList` | `DrawsMoby` | `titles/spyro1/core/frame/dragon_shrink.cpp` | g_SonyImage.u.m_Draw: unk_0x1600, set when the setup found a moby to draw, then the two scale vectors at unk_0x161C and unk_0x1622. |
| `0x800720F4` | `g_apSpritePrimQueue` | `ShadedMobyList` | `titles/spyro1/core/moby/native_shaded_moby_queue.cpp` | g_SonyImage.m_ShadedMobys |
| `0x800724F4` | `g_anActorShadowQueue` | `TallyGems` | `titles/spyro1/core/frame/draw_motion.h` | The level-transition tally's gem records, which AnimateGemTallyParticles points g_pGemTallyParticleRecords at each tick. |
| `0x800730EC` | `g_dwSpuLiveKeyOnMask` | `SpuKeyStatus` | `titles/spyro1/core/audio/spu_library.h` | The keys the SPU holds down. |
| `0x800730F0` | `g_nSpuTransferMode` | `SpuTransferMode` | `titles/spyro1/core/audio/native_spu_transfer_mode.cpp` | The two words the body stores through, each its own `lui $at,0x8007` plus a 16-bit displacement at 0x8005CB9C and 0x8005CBA4. The first is the mode itself, read back at 0x8005CBB4; the second only ever holds 1 or 0 and is read as a boolean  |
| `0x80073114` | `g_dwSpuDeferredKeyOnMask` | `SioKeyBits` | `titles/spyro1/core/audio/native_audio_key_state.cpp` |  |
| `0x80073118` | `g_dwSpuDeferredFlushPending` | `KeyUpdatePending` | `titles/spyro1/core/audio/native_audio_key_state.cpp` |  |
| `0x80073578` | `g_nSpuAddrAlignEnable` | `SpuPitchRoundingGuard` | `titles/spyro1/core/audio/spu_library.h` | SpuSetVoicePitch's rounding. |
| `0x8007357C` | `g_nSpuAddrShift` | `SpuFieldShift` | `titles/spyro1/core/audio/spu_library.h` | The 5-bit scale between a guest quantity and its register field. |
| `0x80073580` | `g_nSpuAddrAlignUnit` | `SpuPitchRoundingStep` | `titles/spyro1/core/audio/spu_library.h` |  |
| `0x80073584` | `g_dwSpuAddrAlignMask` | `SpuPitchRoundingMask` | `titles/spyro1/core/audio/spu_library.h` |  |
| `0x80073928` | `g_apfnIrqHandlers` | `RootHandlers` | `titles/spyro1/core/frame/frame_driver.cpp` |  |
| `0x800749E0` | `g_nRcntAuxState` | `VblankCounter` | `titles/spyro1/core/frame/frame_driver.cpp` |  |
| `0x80074B7C` | `g_nGpuWatchdogDeadline` | `LibgpuTimeoutDeadlineWord` | `titles/spyro1/core/runtime/runtime.cpp` |  |
| `0x80074B80` | `g_nGpuWatchdogSpinCount` | `LibgpuTimeoutFlagWord` | `titles/spyro1/core/runtime/runtime.cpp` |  |
| `0x80074B84` | `g_anSqrtLUT` | `MagnitudeTable` | `titles/spyro1/core/guest_globals.h` | D_80074B84: the reciprocal-magnitude table the guest's normalisation reads after the GTE's leading-zero count. |
| `0x80075264` | `g_abSpyroFlameTransitionModes` | `GuestGpGp` | `titles/spyro1/core/guest_gp.h` |  |
| `0x80075268` | `g_abSpyroFlameAnimTable` | `AnimationSlot` | `titles/spyro1/core/effect/native_effect_state.cpp` | D_80075268, the animation-detail slot |
| `0x800755A4` | `g_nCrt0StackSize` | `StackSize` | `titles/spyro1/core/moby/native_shared_models.cpp` |  |
| `0x8007566C` | `g_nCutsceneId` | `CutsceneIdx` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x8007567C` | `g_pfnFlightResultsDraw` | `Gamestate7DrawHook` | `titles/spyro1/core/moby/native_level_globals_table.cpp` | g_pfnGamestate7DrawHook |
| `0x80075680` | `g_pPathTableHead` | `CutsceneLayout` | `titles/spyro1/core/guest_globals.h` | g_CutsceneLayout (loaders.c), written once at 0x80014A38; m_CurrentTick is its first word. |
| `0x8007568C` | `g_nMenuTickFrames` | `MenuTicks` | `titles/spyro1/core/guest_globals.h` | The menu states' update tick. |
| `0x80075690` | `g_nFlightLevelActive` | `IsFlightLevel` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x80075694` | `g_pfnLevelEndFlightRun` | `FallImpactCallback` | `titles/spyro1/core/moby/native_level_globals_table.cpp` | g_pfnLevelFallImpactCallback |
| `0x800756A4` | `g_nActorPoolLiveCount` | `DynMobyCount` | `titles/spyro1/core/moby/native_moby_allocator.cpp` | g_DynMobyCount (moby.h:507), bumped once per call before either pool is touched. |
| `0x800756AC` | `g_nLevelTransitionPhase` | `TallyPhase` | `titles/spyro1/core/frame/draw_motion.h` |  |
| `0x800756B0` | `g_nLevelTransitionTallyActive` | `LevelTransHudActive` | `titles/spyro1/core/guest_globals.h` | g_LevelTransHudActive: func_8002DA74 ends the level-transition tally by clearing it. |
| `0x800756BC` | `g_pfnLevelAdvanceEmitList` | `Gamestate0LateHook` | `titles/spyro1/core/moby/native_level_globals_table.cpp` | g_pfnGamestate0LateHook |
| `0x800756C0` | `g_nLetterboxBarHeight` | `BorderSize` | `titles/spyro1/core/frame/draw_motion.h` | The section's own counters: the border height and portal yaw it ages before reading, the field tick the portal pulse reads and the specular time the life orbs pulse with (& 0xFF). |
| `0x800756C4` | `g_nActorFrameDelta` | `FrameLag` | `titles/spyro1/core/guest_globals.h` | The fields the last update took (3 and 4 stretch moby animation). |
| `0x800756CC` | `g_nFrameStep` | `DeltaTime` | `titles/spyro1/core/guest_globals.h` |  |
| `0x800756D8` | `g_nPadIsDualshockFlag` | `ActAvailable` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x800756DC` | `g_nCameraShakeMagnitude` | `ScreenShakeFirst` | `titles/spyro1/core/camera/native_camera.cpp` | The pair the preset reset clears last. src/camera.c files both under the camera's screen shake and names neither, so they are named for the order this body reaches them in. D_800756DC |
| `0x800756E0` | `g_nCdStallTimeoutTicks` | `RequestToken` | `titles/spyro1/core/execution/cd_queue.cpp` |  |
| `0x800756F0` | `g_anSecondaryActorTexWords` | `ReflectionTexture` | `titles/spyro1/render/lit_actor_emitter.cpp` | 0x800756F0: the reflection texture's clut and page words. |
| `0x800756FC` | `g_pSpriteRecordBufferTop` | `HudMobyArenaEnd` | `titles/spyro1/core/guest_globals.h` |  |
| `0x80075704` | `g_nCreditsMode` | `CreditsStage` | `titles/spyro1/core/frame/draw_section.cpp` | The credits draw is chosen by `slti g_CreditsStage, 99` at 0x8001EF54. func_credits_8007BFD0, GS_Credits while g_CreditsStage is past its first frame (-1, a MoveImage) and below 99: its letters, then DrawFade(2, g_Fade << 4) called at 0x800 |
| `0x8007570C` | `g_nCinematicActive` | `ScreenBorder` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x80075710` | `g_pSpriteRecordWriteCursor` | `HudMobys` | `titles/spyro1/core/guest_globals.h` | g_HudMobys and D_800756FC: screen-space mobys a frame builds (text, menus) are taken 0x58 bytes at a time down from the arena end, which GamestateDraw sets 0x1C000 past the draw buffer's packets. |
| `0x80075714` | `g_nDemoMode` | `DemoMode` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x80075720` | `g_nPauseMenuCursor` | `PauseMenuCursor` | `titles/spyro1/core/guest_globals.h` |  |
| `0x8007572C` | `g_dwGamestateFrames` | `GameTick` | `titles/spyro1/core/guest_globals.h` |  |
| `0x80075734` | `g_pfnLevelUpdateActors` | `UpdateMoby` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x80075738` | `g_pEmitListWriteCursor` | `PoolCursor` | `titles/spyro1/core/effect/native_particle_alloc.cpp` |  |
| `0x8007573C` | `g_pActorPoolFreeHead` | `MobyAllocCursor` | `titles/spyro1/core/moby/native_moby_allocator.cpp` | g_MobyAllocPtr walks up through 0x58-byte slots; +0x48 is both link byte and alive flag. |
| `0x80075744` | `g_nSubMenuCursor` | `InventoryPage` | `titles/spyro1/core/guest_globals.h` | D_80075744: the inventory page shown; D_800757CC slides between pages and jumps by 0x380 as this changes. |
| `0x80075748` | `g_nMusicVolume` | `MusicVolumeSetting` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x8007574C` | `g_pfnActorCutsceneSubstateUpdate` | `PrimaryTailHook2` | `titles/spyro1/core/moby/native_level_globals_table.cpp` | _DAT_8007574c |
| `0x80075754` | `g_nSfxVolume` | `SoundVolumeSetting` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x8007575C` | `g_nFadeProgress` | `FadeStep` | `titles/spyro1/render/portals.h` | D_8007575C and D_800757D4: how far into the fade band the portal is, and the colour it fades to. |
| `0x80075760` | `g_nFrameTicks` | `UnprocessedFrames` | `titles/spyro1/core/guest_globals.h` |  |
| `0x80075764` | `g_nVibrationLevel` | `ShockTicks` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x80075778` | `g_pActorSpatialGridBase` | `MobyCollisionChain` | `titles/spyro1/core/guest_globals.h` | Per collision region, the head of its moby chain. |
| `0x80075780` | `g_pPrimBufferLimit` | `PacketPoolEnd` | `titles/spyro1/render/terrain_facts.h` | The packet pool's end, which GamestateDraw 0x8001ED5C sets kPacketPoolBytes past the cursor (8001EDC4). |
| `0x80075798` | `g_pPortalDeferredTriStackTop` | `PieceQueue` | `titles/spyro1/render/portals.h` | D_80075798: where the clipped pieces the near sky queues start. |
| `0x8007579C` | `g_nSkipGamestateDraw` | `StateSwitch` | `titles/spyro1/core/guest_globals.h` |  |
| `0x800757A0` | `g_pfnLevelBeginActorCutscene` | `PrimaryTailHook0` | `titles/spyro1/core/moby/native_level_globals_table.cpp` | _DAT_800757a0 |
| `0x800757A4` | `g_nOptionVibrationEnabled` | `ActEnabled` | `titles/spyro1/core/execution/native_level_initialization.cpp` |  |
| `0x800757A8` | `g_pfnLevelHandleFlightResults` | `SecondaryHook0` | `titles/spyro1/core/moby/native_level_globals_table.cpp` | _DAT_800757a8 |
| `0x800757B0` | `g_pPrimBufferWriteCursor` | `PolyCursor` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x800757C0` | `g_pfnFlightResultsUpdate` | `Gamestate7Handler` | `titles/spyro1/core/moby/native_level_globals_table.cpp` | g_pfnGamestate7Handler |
| `0x800757C8` | `g_nPauseMenuSubstate` | `MenuScreen` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x800757D4` | `g_dwSkyFadeColor` | `FadeColour` | `titles/spyro1/render/portals.h` |  |
| `0x80075810` | `g_nTotalEggsRecovered` | `LevelTarget` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x8007581C` | `g_pOtActiveDepthSlot` | `OverlayLinkPairWord` | `titles/spyro1/core/execution/native_util.cpp` |  |
| `0x80075820` | `g_pOtDepthBinArrayBase` | `WorldOt` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x80075824` | `g_pEmitListBase` | `ListBase` | `titles/spyro1/render/particles.h` | g_pEmitListBase: the first record. A record whose kind halfword is 0xFFxx ends the list. |
| `0x80075828` | `g_pActorListBase` | `LevelMobys` | `titles/spyro1/core/guest_globals.h` | g_LevelMobys (moby.h): pointer to the level's Moby array. |
| `0x8007582C` | `g_nExtraLives` | `WaitCounter` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x80075830` | `g_nLevelKeyState` | `TreasureTotal` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x80075858` | `g_nPortalSkyYawSpin` | `PortalYaw` | `titles/spyro1/core/frame/draw_motion.h` |  |
| `0x80075864` | `g_nCdStreamState` | `LoadStage` | `titles/spyro1/core/guest_globals.h` | g_LoadStage (main.c): the streaming/load phase the main loop and the boot sequence both watch. |
| `0x80075888` | `g_pActiveFrameDrawEnv` | `GuestGlobalsCurDb` | `titles/spyro1/core/guest_globals.h` |  |
| `0x8007588C` | `g_nCdStallWatchdogTicks` | `CallbackState` | `titles/spyro1/core/execution/cd_queue.cpp` |  |
| `0x80075890` | `g_pActorPoolDynBase` | `DynMobys` | `titles/spyro1/core/moby/native_moby_allocator.cpp` | The first dynamic moby; one below it is only marked. |
| `0x800758A8` | `g_pfnLevelOnSaveMenuExit` | `PrimaryTailHook1` | `titles/spyro1/core/moby/native_level_globals_table.cpp` | _DAT_800758a8 |
| `0x800758B0` | `g_nPrimBufferOverflowFlag` | `DrawSectionUnread` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x800758B4` | `g_nNextLevelId` | `NextLevelId` | `titles/spyro1/core/guest_globals.h` |  |
| `0x800758B8` | `g_nMenuDrawFrames` | `MenuDraws` | `titles/spyro1/core/guest_globals.h` | The menu states' draw count; GS_ExitLevel counts its passes in it. |
| `0x800758BC` | `g_nPortalCount` | `PortalCount` | `titles/spyro1/core/guest_globals.h` |  |
| `0x800758C4` | `g_pfnFlightTimeFormatter` | `SecondaryHook1` | `titles/spyro1/core/moby/native_level_globals_table.cpp` | _DAT_800758c4 |
| `0x800758C8` | `g_nVblankTickCount` | `LevelTicks` | `titles/spyro1/core/guest_globals.h` | The main loop's clocks: g_LevelTicks per field from VSync, g_GameTick per GS_Playing update, g_UnprocessedFrames, g_DeltaTime, g_StateSwitch. |
| `0x800758CC` | `g_pfnLevelSpawnActor` | `OverlayInitHook` | `titles/spyro1/core/moby/native_level_globals_table.cpp` | The globals the body writes, named where the decomp names them and by their position in the bank where it leaves them as _DAT_ globals. g_pfnLevelOverlayInitHook |
| `0x800758D8` | `g_pfnActorCutsceneSubstateDraw` | `TransitionDrawHook` | `titles/spyro1/core/moby/native_level_globals_table.cpp` | gamestate 0xC's draw hook |
| `0x800758E4` | `g_pfnLevelEmitParticles` | `EmitterFunction` | `titles/spyro1/core/effect/native_effect_state.cpp` |  |
| `0x800758E8` | `g_nSparxFoodCount` | `WaitTimer` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x800758EC` | `g_nLevelSelectWorldIndex` | `CheatHomeworldSelected` | `titles/spyro1/core/guest_globals.h` | cheat_HomeworldSelected (cheats.c): the homeworld CheatProcessLevelWarp adds the level button to. |
| `0x800758FC` | `g_nPortalSkyPitchTilt` | `SkyPitch` | `titles/spyro1/render/portals.h` |  |
| `0x80075900` | `g_nFlightQuitFlag` | `ExitLevelFlag` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x8007590C` | `g_nCameraShakeDuration` | `ScreenShakeSecond` | `titles/spyro1/core/camera/native_camera.cpp` | D_8007590C |
| `0x80075910` | `g_nTransitionSkyPitchTilt` | `SkyTilt` | `titles/spyro1/core/frame/draw_motion.h` |  |
| `0x80075914` | `g_dwActiveCameraOptions` | `CameraMode` | `titles/spyro1/core/execution/native_level_initialization.cpp` |  |
| `0x80075918` | `g_nScreenFadeLevel` | `GuestGlobalsFade` | `titles/spyro1/core/guest_globals.h` | g_Fade: the screen fade GamestateDraw and TitlescreenDraw draw while it is non-zero. |
| `0x8007591C` | `g_nPortalDistanceFogEnabled` | `SkipLowPolyWorld` | `titles/spyro1/core/guest_globals.h` | g_SkipLowPolyWorld: non-zero skips the far terrain pass; the actor emitter parks it in ZSF3 for fog. |
| `0x80075930` | `g_pActorAuxPoolFreeHead` | `PropsAllocCursor` | `titles/spyro1/core/moby/native_moby_allocator.cpp` | g_PropsAllocPtr walks down through 24-byte records; a record's link byte sits just below it. |
| `0x80075934` | `g_nPortalOtDepthBin` | `PortalsBin` | `titles/spyro1/render/portals.h` | D_80075934: the depth bin the fill is linked into. |
| `0x8007593C` | `g_nRespawnOrGameOverFrame` | `GameplayDrawFrame` | `titles/spyro1/core/guest_globals.h` | Non-zero while the respawn/game-over arm fades over a frozen gameplay frame. |
| `0x80075944` | `g_bPadInputStashed` | `PadSwapFlag` | `titles/spyro1/core/input/native_gamepad.cpp` | g_PadSwapFlag (gamepad.h): both the `lui 0x8007` load and the `lui 0x8007` store form 0x5944, so the flag this body toggles is one byte at 0x80075944. |
| `0x80075964` | `g_nLevelIndex` | `LevelIndex` | `titles/spyro1/core/effect/native_effect_state.cpp` | g_LevelIndex |
| `0x8007596C` | `g_nActiveLevelId` | `LevelId` | `titles/spyro1/core/guest_globals.h` | g_LevelId and g_NextLevelId: current and requested level identifiers. |
| `0x80075AC0` | `g_dwRandSeed` | `NativeRandSeed` | `titles/spyro1/core/execution/native_rand.cpp` |  |
| `0x80075EF8` | `g_anActorShadowTexWords` | `ShadowListHolder` | `titles/spyro1/render/actor_facts.h` | The words the pass ends return in $v0 (8001F74C). |
| `0x80075F00` | `g_pEntityListEnd` | `ShadowListEnd` | `titles/spyro1/render/actor_facts.h` | g_anEntitySpikeTexWords + 8: the shadow list's end, carried from pass to pass. |
| `0x80075F18` | `g_nCdDaVolumeCurrent` | `SpuCdVolumeLeft` | `titles/spyro1/core/guest_globals.h` | g_Spu (spu.h): the CD volume CDMusicUpdate (0x8002BBE0) steps by m_MusicFadeCurrent toward m_MusicFadeTarget; the fade ends once the step passes the target. i16 |
| `0x80075F1A` | `g_nSpuCommonCdVolumeR` | `MusicVolumeRight` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x80075F30` | `g_aSpuVoiceRows` | `ActiveSounds` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x800761D0` | `g_pLevelSampleBankEntries` | `SoundRecordTable` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x800761D4` | `g_pLevelSampleBankHeader` | `NativePauseMenuSpu` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x800761D8` | `g_nMusicVolumeFadeTarget` | `SpuMusicFadeTarget` | `titles/spyro1/core/guest_globals.h` |  |
| `0x800761DC` | `g_nSfxOverrideFlags` | `SoundStateFlags` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x800761E8` | `g_nSfxOverrideVolL` | `PresetGainLeft` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x800761EA` | `g_nSfxOverrideVolR` | `PresetGainRight` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x800761F4` | `g_nSfxOverridePitch` | `RecordGain` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x80076224` | `g_nCdAudioVolume_blk` | `MusicVolume` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x80076228` | `g_nSfxMixVolume_blk` | `SoundVolumeScale` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x8007622C` | `g_nSoundMasterVolume` | `GlobalGainScale` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x80076230` | `g_nMusicVolumeFadeStep` | `SpuMusicFadeCurrent` | `titles/spyro1/core/guest_globals.h` |  |
| `0x80076238` | `g_dwSpuPendingKeyOn` | `SlotChangedMask` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x8007623C` | `g_dwSpuPendingKeyOff` | `StopVoiceWord` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x80076240` | `g_nSoundMonoMixFlag` | `AudioMonoFlag` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x80076248` | `g_nDragonRescueAuraStarEnabled` | `RescueStarBlock` | `titles/spyro1/render/rescue_star.h` |  |
| `0x80076278` | `g_apEmitTextureTable` | `TextureGroups` | `titles/spyro1/render/particles.h` | Per texture group, a table of 8-byte frames whose +4 and +8 words are a quad's UV words. |
| `0x80076378` | `g_apActorMeshTable` | `GuestGlobalsModels` | `titles/spyro1/core/guest_globals.h` | g_Models (moby.h): the Model pointer per class, indexed by moby +0x36; Spyro's own is entry 0. |
| `0x8007637C` | `g_apActorMeshTable_1` | `ModelList` | `titles/spyro1/core/player/native_cutscene.cpp` | A layout moby animates g_Models[index + 1] and is written into g_LevelMobys[index]. |
| `0x80076B80` | `g_anCollisionResolvedPos` | `CollisionPoint` | `titles/spyro1/core/camera/native_camera.cpp` | g_CollisionPoint |
| `0x80076B88` | `g_nCollisionResolvedZ` | `CollisionHitZ` | `titles/spyro1/core/moby/native_collision_shade.cpp` |  |
| `0x80076B90` | `g_nCdBaseLba` | `OverlaySpacePointer` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x80076B94` | `g_nCdReadSectorCount` | `TransferSectorCount` | `titles/spyro1/core/execution/cd_queue.cpp` |  |
| `0x80076B98` | `g_abCdlLocScratch` | `TransferPosition` | `titles/spyro1/core/execution/cd_queue.cpp` |  |
| `0x80076B9C` | `g_pCdReadDstBuffer` | `TransferDestination` | `titles/spyro1/core/execution/cd_queue.cpp` |  |
| `0x80076BB8` | `g_nCdReadInFlight` | `CdQueueGate` | `titles/spyro1/core/execution/cd_queue.cpp` |  |
| `0x80076DD0` | `g_anWorldToCameraRotMtx` | `GuestGlobalsCamera` | `titles/spyro1/core/guest_globals.h` | g_Camera: the occlusion group selects which collision groups the scene admits; the rotation is three halfwords read by both the camera and cutscene owners. |
| `0x80076DE4` | `g_anCameraViewMtx` | `SharedFactsViewRotation` | `titles/spyro1/render/terrain_facts.h` |  |
| `0x80076E04` | `g_anCameraEyeTarget` | `CameraDestination` | `titles/spyro1/core/camera/native_camera.cpp` | g_Camera (external/spyro-1/include/camera.h), base 0x80076DD0, and the three globals outside it this body touches. Each is the `lui`+`addiu` pair the retail code builds.  m_LastSimulation is the six-word copy the preset reset reloads the ro |
| `0x80076E28` | `g_nCameraCurrentMode` | `CameraState` | `titles/spyro1/core/camera/native_camera.cpp` | m_State |
| `0x80076E30` | `g_nCameraTargetYaw` | `CameraLastSimulation` | `titles/spyro1/core/camera/native_camera.cpp` | m_LastSimulation |
| `0x80076E48` | `g_nCameraSpringYaw` | `CameraSphereAzimuth` | `titles/spyro1/core/camera/native_camera.cpp` | g_Camera.m_Sphere's FIRST row, which is kCameraSphereRows below: the leaf below converts these three words, m_Coords, in the same azimuth/elevation/radius order that row's angle fields use. |
| `0x80076E4C` | `g_nCameraSpringPitch` | `CameraSphereElevation` | `titles/spyro1/core/camera/native_camera.cpp` |  |
| `0x80076E50` | `g_nCameraSpringDistance` | `CameraSphereRadius` | `titles/spyro1/core/camera/native_camera.cpp` |  |
| `0x80076E54` | `g_nCameraSpringRoll` | `SphereOffsetAzimuth` | `titles/spyro1/core/camera/native_camera.cpp` | g_Camera (camera.h), base 0x80076DD0: the spherical inputs the body reads are five words at +0x84..+0x94, and the rotation it writes is the three halfwords named above. |
| `0x80076E58` | `g_nCameraSpringPitchBias` | `SphereOffsetElevation` | `titles/spyro1/core/camera/native_camera.cpp` |  |
| `0x80076E5C` | `g_nCameraSpringYawBias` | `SphereOffsetRadius` | `titles/spyro1/core/camera/native_camera.cpp` |  |
| `0x80076E60` | `g_nCameraYaw` | `SimulationAzimuth` | `titles/spyro1/core/camera/native_camera.cpp` |  |
| `0x80076E64` | `g_nCameraPitch` | `SimulationElevation` | `titles/spyro1/core/camera/native_camera.cpp` |  |
| `0x80076E68` | `g_nCameraDistance` | `SimulationRadius` | `titles/spyro1/core/camera/native_camera.cpp` | m_Simulation.m_Coords.z |
| `0x80076E6C` | `g_nCameraDraftRoll` | `SimulationOffsetX` | `titles/spyro1/core/camera/native_camera.cpp` | m_Simulation.m_Offset.x |
| `0x80076E70` | `g_nCameraDraftPitchBias` | `SimulationOffsetY` | `titles/spyro1/core/camera/native_camera.cpp` | m_Simulation.m_Offset.y |
| `0x80076E74` | `g_nCameraDraftYawBias` | `SimulationOffsetZ` | `titles/spyro1/core/camera/native_camera.cpp` | m_Simulation.m_Offset.z |
| `0x80076E78` | `g_anCameraSpringDeltaState` | `CameraClearedGroup` | `titles/spyro1/core/camera/native_camera.cpp` | unk_0xA8, the six words zeroed |
| `0x80076E94` | `g_nCameraCollisionRetries` | `CameraCollisionCounter` | `titles/spyro1/core/camera/native_camera.cpp` | unk_0xC4 |
| `0x80076E98` | `g_nCameraStuckFrames` | `CameraSpyroOffCenterFrames` | `titles/spyro1/core/camera/native_camera.cpp` |  |
| `0x80076E9C` | `g_nCameraSnapped` | `CameraForcedToDestination` | `titles/spyro1/core/camera/native_camera.cpp` | unk_0xCC |
| `0x80076EA0` | `g_pCameraAnchorPos` | `CameraFocusPointer` | `titles/spyro1/core/camera/native_camera.cpp` | m_Focus, loaded as an address |
| `0x80076EA8` | `g_pCameraTargetParams` | `CameraSphericalPreset` | `titles/spyro1/core/camera/native_camera.cpp` | m_SphericalPreset |
| `0x80076EB8` | `g_nCameraTargetInverted` | `CameraAzimuthChanged` | `titles/spyro1/core/camera/native_camera.cpp` | unk_0xE8 |
| `0x80076EE0` | `g_FrameDrawEnv0` | `GuestGlobalsDb0` | `titles/spyro1/core/guest_globals.h` | g_DB[2], the current one (g_CurDB) and each one's packet pool pointer; a frame's built mobys are taken down from terrain::kPacketPoolBytes past a pool. |
| `0x80076F50` | `g_pFramePrimBufferBase0` | `PublishedOrderingZero` | `titles/spyro1/core/frame/native_draw_setup.cpp` | Where the reset republishes the ordering and pool pointers for the rest of the draw area. |
| `0x80076F54` | `g_pFrameOtDepthBinBase0` | `PublishedPrimPool` | `titles/spyro1/core/frame/native_draw_setup.cpp` |  |
| `0x80076F58` | `g_pFrameOtMergedChainSlot0` | `PublishedOrderingAnchor` | `titles/spyro1/core/frame/native_draw_setup.cpp` |  |
| `0x80076F64` | `g_FrameDrawEnv1` | `GuestGlobalsDb1` | `titles/spyro1/core/guest_globals.h` |  |
| `0x80076FD4` | `g_pFramePrimBufferBase1` | `PublishedOrderingOne` | `titles/spyro1/core/frame/native_draw_setup.cpp` |  |
| `0x80076FD8` | `g_pFrameOtDepthBinBase1` | `PublishedPrimPoolAlt` | `titles/spyro1/core/frame/native_draw_setup.cpp` |  |
| `0x80076FDC` | `g_pFrameOtMergedChainSlot1` | `PublishedOrderingAnchorAlt` | `titles/spyro1/core/frame/native_draw_setup.cpp` |  |
| `0x80077030` | `g_abDragonRescueAssetHeader` | `DragonCutscene` | `titles/spyro1/core/guest_globals.h` | g_DragonCutscene (dragon.h): state machine after 0x24-byte WAD header. |
| `0x800770C8` | `g_anWorldLightDirVec` | `SpecularAndMetal` | `titles/spyro1/core/guest_globals.h` | D_800770C8 (specular_and_metal.h): SpecularAndMetal. |
| `0x80077108` | `g_aRotBillboards` | `Sparkles` | `titles/spyro1/render/glows.h` | g_Sparkles |
| `0x800771C8` | `g_abWorldChunkDrawn` | `CategoryVisibility` | `titles/spyro1/core/moby/native_moby_lists.cpp` |  |
| `0x80077368` | `g_anCollisionHitNormal` | `CollisionNormal` | `titles/spyro1/core/moby/native_collision_shade.cpp` | g_CollisionNormal (game.bss.s:87) — the three words the raycast leaves the surface normal in, read here as x/y/z. g_CollisionPoint's third word is the only part of the hit point the body reads, and it becomes the low channel of the packed w |
| `0x80077378` | `g_dwPadPressed` | `GuestGlobalsPad` | `titles/spyro1/core/guest_globals.h` | g_Pad (gamepad.h): m_Down at +0, m_Released at +4, m_Held at +8. |
| `0x80077380` | `g_dwPadHeld` | `PadHeld` | `titles/spyro1/core/camera/native_camera.cpp` |  |
| `0x80077420` | `g_anLevelGemsCollected` | `LevelGemCount` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x800774B4` | `g_dwMusicStreamStatus` | `CdMusicFlags` | `titles/spyro1/core/guest_globals.h` | g_CdMusic.m_Flags (music.h): 0x200 while the music fades down, 0x40 once the drive is free. |
| `0x800776D0` | `g_bCdMixLeftToLeft` | `CdMixVolume` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x80077DD8` | `g_anStaticRegSaveArea` | `RegisterSpillArea` | `titles/spyro1/core/guest_globals.h` | D_80077DD8: guest callees spill s0..s7, gp, sp, fp, ra here before reading arguments. |
| `0x80077EA0` | `g_aPortalSilhouetteEdges` | `PortalsEdges` | `titles/spyro1/render/portals.h` | D_80077EA0: the outline's edges, 0x18 bytes each, ended by a zero flag. |
| `0x80077FA8` | `g_abHudCounterDisplayState` | `DrawMotionHud` | `titles/spyro1/core/frame/draw_motion.h` | g_Hud.m_Mobys[12]: the count and icon mobys slide in y and spin in z; a digit, substate or radius change is another object (HudMobyRotate). |
| `0x80077FEC` | `g_aHudIconActorRecords` | `IconRecords` | `titles/spyro1/render/hud_anchor.h` |  |
| `0x80078560` | `g_nWorldAnimTextureFrameCount` | `NodeLists` | `titles/spyro1/core/moby/scroll_bake.h` | 0x8002A6FC's node lists, each a count then the node pointer array; the scroll list is the second. |
| `0x800785A8` | `g_pWorldChunkArray` | `Environment` | `titles/spyro1/core/guest_globals.h` | g_Environment (environment.h): +0x0C is the occlusion group count, +0x2C the collision header. |
| `0x800785C0` | `g_pWorldTextureLodRecords` | `NarrowRecords` | `titles/spyro1/core/moby/scroll_bake.h` | Pointers to the record tables. |
| `0x800785C4` | `g_pWorldTextureDetailRecords` | `WideRecords` | `titles/spyro1/core/moby/scroll_bake.h` |  |
| `0x800785D4` | `g_pWorldCollisionHeader` | `TerrainCollision` | `titles/spyro1/core/moby/native_environment_light.cpp` | g_Environment + 0x2C, the TerrainCollision pointer, and the vertex block its +0x10 holds. BOTH arms of the blend reach it through the same two loads: `0x8002AE40 lw $a2,0x2C($a2)` is the delay slot of the arm test, so it runs whichever arm  |
| `0x800785D8` | `g_pLoadStagingBuffer` | `CopyBuf` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x800785DC` | `g_pLevelDataBuffer` | `DiscCopyBuf` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x800785E8` | `g_pRenderScratchRegionBase` | `OrderingZero` | `titles/spyro1/core/frame/native_draw_setup.cpp` |  |
| `0x800785EC` | `g_pRenderScratchPrimBase1` | `OrderingOne` | `titles/spyro1/core/frame/native_draw_setup.cpp` |  |
| `0x800785F0` | `g_pRenderScratchPrimTop` | `OrderingAnchor` | `titles/spyro1/core/frame/native_draw_setup.cpp` |  |
| `0x800785F4` | `g_pRenderScratchOtBase` | `PrimPool` | `titles/spyro1/core/frame/native_draw_setup.cpp` |  |
| `0x800785F8` | `g_pEmitListBuffer` | `ArenaSlot` | `titles/spyro1/core/frame/native_draw_setup.cpp` |  |
| `0x800785FC` | `g_pWorkAreaTop` | `ArenaBase` | `titles/spyro1/core/frame/native_draw_setup.cpp` | The drawing arena: 0x800785FC holds its base pointer, the other five globals the two pools, the two orderings, and one arena slot the reset rebases but does not otherwise use. |
| `0x80078640` | `g_apPortals` | `Portals` | `titles/spyro1/core/guest_globals.h` | g_Portals (portal.h): up to six live portal pointers. |
| `0x800786A0` | `g_abPadRawReport` | `PadBuffersSlot0Buffer` | `titles/spyro1/core/runtime/runtime.cpp` |  |
| `0x800786C8` | `g_anSpyroFlameAnchorPos` | `FlameBlockBlock` | `titles/spyro1/core/effect/flame_block.h` |  |
| `0x80078800` | `g_abWorldSparkleParticleTable` | `Emitters` | `titles/spyro1/render/glows.h` |  |
| `0x80078A40` | `g_nSkyChunkCount` | `Cyclorama` | `titles/spyro1/render/sky.h` | g_Cyclorama: the sector count, the sector pointers and the per-group sector byte lists. |
| `0x80078A50` | `g_dwWorldFogColor` | `FogColour` | `titles/spyro1/render/actor_emitter_layout.h` | 8001FEEC: the fog colour. |
| `0x80078A58` | `g_anSpyroWorldPos` | `GuestGlobalsSpyro` | `titles/spyro1/core/guest_globals.h` | g_Spyro (spyro.h): m_Position at +0, m_State at +0x78, m_controlFlags at +0x1F4. |
| `0x80078A70` | `g_bSpyroAnimPrev` | `BodyAnimation` | `titles/spyro1/core/player/native_player_animation.cpp` | g_Spyro.m_bodyAnimation (u8) |
| `0x80078A71` | `g_bSpyroAnimCurrent` | `NextBodyAnimation` | `titles/spyro1/core/player/native_player_animation.cpp` | g_Spyro.m_nextBodyAnimation (u8) |
| `0x80078A74` | `g_bSpyroAnimLayer2Prev` | `TailAnimation` | `titles/spyro1/core/player/native_player_animation.cpp` |  |
| `0x80078A75` | `g_bSpyroAnimLayer2Current` | `NextTailAnimation` | `titles/spyro1/core/player/native_player_animation.cpp` |  |
| `0x80078A76` | `g_bSpyroFramePrev` | `BodyAnimationFrame` | `titles/spyro1/core/player/native_player_animation.cpp` | g_Spyro.m_bodyAnimationFrame (u8) |
| `0x80078A77` | `g_bSpyroAnimFrame` | `NextBodyAnimationFrame` | `titles/spyro1/core/player/native_player_animation.cpp` | g_Spyro.m_nextBodyAnimationFrame |
| `0x80078A79` | `g_bSpyroAnimLayer1Frame` | `SpyroNextHeadFrame` | `titles/spyro1/core/effect/native_effect_state.cpp` | +0x21, m_nextHeadAnimationFrame |
| `0x80078A7A` | `g_bSpyroAnimLayer2FramePrev` | `TailAnimationFrame` | `titles/spyro1/core/player/native_player_animation.cpp` |  |
| `0x80078A7B` | `g_bSpyroAnimLayer2Frame` | `NextTailAnimationFrame` | `titles/spyro1/core/player/native_player_animation.cpp` |  |
| `0x80078A7C` | `g_bSpyroSubFrameTimer` | `BodyFrameProgress` | `titles/spyro1/core/player/native_player_animation.cpp` | g_Spyro.m_bodyFrameProgress (u8) |
| `0x80078A7E` | `g_bSpyroAnimLayer2Substep` | `TailFrameProgress` | `titles/spyro1/core/player/native_player_animation.cpp` |  |
| `0x80078A7F` | `g_bSpyroOtBinBias` | `SpyroColorFilterGreen` | `titles/spyro1/core/camera/native_camera.cpp` | g_Spyro.m_colorFilter.m_green |
| `0x80078A8C` | `g_anSpyroBodyMtx` | `SpyroRotation` | `titles/spyro1/core/effect/native_effect_state.cpp` | g_Spyro (spyro.h) is 0x80078A58, but both bodies form their g_Spyro addresses from the rotation matrix at +0x34 (`lui $s0,0x8008; addiu $s0,$s0,-0x7574`), so each field is spelled as the offset from that one formed address — the displacemen |
| `0x80078AB4` | `g_nSpyroPrevState` | `LastAnimationState` | `titles/spyro1/core/player/native_player_animation.cpp` | g_Spyro.m_lastAnimationState (32-bit) |
| `0x80078AB8` | `g_anSpyroFlamePhaseBlock` | `SpyroFlamePhase` | `titles/spyro1/core/effect/native_effect_state.cpp` | +0x60, unk_0x60 |
| `0x80078ABC` | `g_nSpyroFlameAnimRate` | `SpyroHeadAnimationSpeed` | `titles/spyro1/core/effect/native_effect_state.cpp` | +0x64 |
| `0x80078AC4` | `g_nSpyroAnimLayer2Phase` | `TailAnimationHold` | `titles/spyro1/core/player/native_player_animation.cpp` | The three g_Spyro words beside m_seperateTailAnimation that the decompilation leaves unnamed, named here for the tail stepper's own use of them. |
| `0x80078AC8` | `g_nSpyroAnimLayer2Rate` | `TailAnimationSpeed` | `titles/spyro1/core/player/native_player_animation.cpp` |  |
| `0x80078ACC` | `g_nSpyroAnimLayer2Active` | `TailAnimationMode` | `titles/spyro1/core/player/native_player_animation.cpp` |  |
| `0x80078BEC` | `g_nSpyroScriptedMoveMode` | `HeadLookField` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x80078BF0` | `g_nSpyroFlameState` | `SpyroBurstMode` | `titles/spyro1/core/effect/native_effect_state.cpp` | +0x198, unk_0x198 |
| `0x80078BF8` | `g_nSpyroFlameTimer` | `SpyroBurstTicks` | `titles/spyro1/core/effect/native_effect_state.cpp` | +0x1A0, unk_0x1a0 |
| `0x80078BFC` | `g_nSpyroSwingEulerTargetX` | `SpyroHeadLookTarget` | `titles/spyro1/core/effect/native_effect_state.cpp` | +0x1A4, m_HeadLookTarget |
| `0x80078C20` | `g_anSpyroComposedBodyMtx` | `BurstMatrix` | `titles/spyro1/core/effect/native_effect_state.cpp` | +0x1C8, m_headRotationMatrix |
| `0x80078C40` | `g_nSpyroAnimLayer2Request` | `SeparateTailAnimation` | `titles/spyro1/core/player/native_player_animation.cpp` |  |
| `0x80078C44` | `g_nSpyroAnimLayer2GateFrames` | `FlameableFrames` | `titles/spyro1/core/player/native_player_animation.cpp` |  |
| `0x80078D78` | `g_nTitleMode` | `TitlescreenState` | `titles/spyro1/core/guest_globals.h` | g_TitlescreenState (titlescreen.h): four-byte fields in declaration order. |
| `0x80078DD8` | `g_aPortalRingScreenPts` | `Projected` | `titles/spyro1/render/portals.h` | D_80078DD8: each point's screen x, y and depth, a word each, 16 points at most. |
| `0x8007A6E0` | `g_nLevelLoadByteOffset` | `CdLoadOffset` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x8007A6E4` | `g_nLevelLoadChunkSize` | `CdLoadLength` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x8007A710` | `g_nActorMeshDirSectorOffset` | `PeteWadOffset` | `titles/spyro1/core/moby/native_shared_models.cpp` |  |
| `0x8007A714` | `g_nActorMeshDirByteSize` | `PeteWadLength` | `titles/spyro1/core/moby/native_shared_models.cpp` | g_WadHeader.m_PETE.m_Length and .m_Offset (external/spyro-1/include/wad.h), g_CdState.m_WadSector (cd.h) and _stacksize: each is the `lui` plus immediate pair the retail body builds. |
| `0x8007AA00` | `g_anPortalScissorRect` | `PortalsWindow` | `titles/spyro1/render/portals.h` | D_8007AA00: the outline's bounding window, top, bottom, right and left, each << 16. |
| `0x8007AA10` | `g_abSpyroShadowRingHeights` | `ShadowBlockBlock` | `titles/spyro1/core/effect/shadow_block.h` |  |
| `0x8007AA2C` | `g_nSpyroShadowOtBinBias` | `SpyroShadowUnknown1C` | `titles/spyro1/core/camera/native_camera.cpp` | D_8007AA10.unk_1c |

## Names added to the map

| address | added as | was | port file | meaning |
|---|---|---|---|---|
| `0x8006C558` | `g_FlameBlockedInAnimation` | `-` | `titles/spyro1/core/effect/native_effect_state.cpp` | spyro_FlameBlockedInAnimation |
| `0x8006CC38` | `g_NativePlayerPhysicsProbeY` | `-` | `titles/spyro1/core/player/native_player_physics.cpp` |  |
| `0x8006CCB8` | `g_NativePlayerPhysicsProbeX` | `-` | `titles/spyro1/core/player/native_player_physics.cpp` | The four ground probes read a direction pair each, 0x80 bytes apart, from the sin and cos tables guest_globals.h names. The loop takes the X word from one table and the Y word from the other with a single index, and the tail then indexes th |
| `0x8006E3D8` | `g_Palette` | `-` | `titles/spyro1/render/actor_facts.h` | A record's +0x4C word picks its base colour here (>> 22) and its flat-shaded pair (>> 21). |
| `0x8006E44C` | `g_FlatPalette` | `-` | `titles/spyro1/render/actor_facts.h` |  |
| `0x80070000` | `g_SpuStateSegment` | `-` | `titles/spyro1/core/audio/native_spu_transfer_mode.cpp` | The high half both `lui $at` instructions leave in $at. |
| `0x80071310` | `g_DragonShrinkScale` | `-` | `titles/spyro1/core/frame/dragon_shrink.cpp` |  |
| `0x80071316` | `g_TurnScale` | `-` | `titles/spyro1/core/frame/dragon_shrink.cpp` |  |
| `0x8007354C` | `g_KeyTransferMode` | `-` | `titles/spyro1/core/audio/native_audio_key_state.cpp` |  |
| `0x80073554` | `g_SpuRegisterBase` | `-` | `titles/spyro1/core/audio/spu_library.h` | Initialised to 0x1F801C00, voice 0's left volume; indexed as the SPU register file. |
| `0x80073568` | `g_SpuStatePointer` | `-` | `titles/spyro1/core/audio/spu_library.h` | The library's pointer to its own state structure. |
| `0x80073570` | `g_SpuModeIsOne` | `-` | `titles/spyro1/core/audio/native_spu_transfer_mode.cpp` |  |
| `0x80074E38` | `g_NativeUtilG3C30` | `-` | `titles/spyro1/core/execution/native_util.cpp` | 0x80063C30 — set a global, return its PREVIOUS value. lui v0,0x8007 ; lw v0,0x4E38(v0) ; lui at,0x8007 ; sw a0,0x4E38(at) ; jr ra The load of the old value precedes the store, so this is a swap rather than a plain setter. The address is for |
| `0x80074E50` | `g_CdWorkAreaLastPositionAddress` | `-` | `titles/spyro1/core/runtime/runtime.cpp` | Written by libcd's command send: Setloc 0x80064DDC, Setmode 0x80064E08, command byte 0x80064EA4. |
| `0x80074E54` | `g_CdWorkAreaLastModeAddress` | `-` | `titles/spyro1/core/runtime/runtime.cpp` |  |
| `0x80074E55` | `g_CdWorkAreaLastCommandAddress` | `-` | `titles/spyro1/core/runtime/runtime.cpp` |  |
| `0x800777A8` | `g_SioKeyPositionModeOne` | `D_800777A8` | `titles/spyro1/core/audio/native_audio_key_state.cpp` | The SIO records are one 8-byte block: mode 1 writes the pair at +0, mode 0 the pair at +4, and each mode withdraws the bits of the pair the other one wrote. |
| `0x800777AC` | `g_SioKeyPositionModeZero` | `D_800777AC` | `titles/spyro1/core/audio/native_audio_key_state.cpp` |  |
| `0x80078191` | `g_SparkShadeByte` | `D_80078191` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x80078192` | `g_SparkTimerByte` | `D_80078192` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x8007829A` | `g_StampShade` | `D_8007829A` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x8007829D` | `g_StampCounter` | `D_8007829D` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x800783A2` | `g_LifeLevelByte` | `D_800783A2` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x800783B4` | `g_RuntimeArgs` | `D_800783B4` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x800783F8` | `g_TailCosine` | `D_800783F8` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x800783F9` | `g_TailSine` | `D_800783F9` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x800783FD` | `g_TailCounter` | `D_800783FD` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x800786C2` | `g_PadBuffersSlot1Buffer` | `-` | `titles/spyro1/core/runtime/runtime.cpp` |  |

## Structure fields

Offsets the port reads inside a named global; they belong in this tree's structure headers.

| port name | base | offset | address | port file | meaning |
|---|---|---|---|---|---|
| `kShoulderRotationSpeed` | `kGp` | `0x6C0` | `0x80075924` | `titles/spyro1/core/camera/native_camera.cpp` | 0x80075924 |
| `kCameraForceFlag` | `kGp` | `0x454` | - | `titles/spyro1/core/camera/native_camera.cpp` | D_800756B8 |
| `kPosition` | `kBlock` | `0x0` | - | `titles/spyro1/core/effect/flame_block.h` | the anchor, x, y, z words |
| `kTexture` | `kBlock` | `0x10` | - | `titles/spyro1/core/effect/flame_block.h` | two ribbon UV words, +8 when superflame |
| `kLengths` | `kBlock` | `0x20` | - | `titles/spyro1/core/effect/flame_block.h` | eight signed bytes, one per part |
| `kLimits` | `kBlock` | `0x28` | - | `titles/spyro1/core/effect/flame_block.h` | signed bytes, each part's last entry |
| `kActive` | `kBlock` | `0x98` | - | `titles/spyro1/core/effect/flame_block.h` | m_IsFlameActive |
| `kState` | `kBlock` | `0x99` | - | `titles/spyro1/core/effect/flame_block.h` |  |
| `kSelect` | `kBlock` | `0x9A` | - | `titles/spyro1/core/effect/flame_block.h` | asks Spyro's draw for the rotation |
| `kVariant` | `kBlock` | `0x9B` | - | `titles/spyro1/core/effect/flame_block.h` | the rand() bit |
| `kSuper` | `kBlock` | `0x9C` | - | `titles/spyro1/core/effect/flame_block.h` | superflame word |
| `kFairyKissTimer` | `kBlock` | `0xA0` | - | `titles/spyro1/core/effect/flame_block.h` | m_FairyKissTimer |
| `kRotation` | `kBlock` | `0xB8` | - | `titles/spyro1/core/effect/flame_block.h` | five RT words, view space |
| `kSpyroSurfaceBelow` | `kSpyroRotation` | `0x6C` | - | `titles/spyro1/core/effect/native_effect_state.cpp` | +0xA0, m_surfaceBelowSpyro |
| `kSpyroState` | `kSpyroRotation` | `0x44` | - | `titles/spyro1/core/effect/native_effect_state.cpp` | +0x78, m_State. The blocked-animation test indexes spyro_StateDefaultAnimation with THIS word, not with the burst mode at +0x198: `0x800499C4 lw $v0,-0x7530($v0)` with $v0 = 0x80080000 is 0x80078AD0, and the mode is only read at 0x800499A20 |
| `kSurfaceProbeReturn` | `kUpdateGroundShadow` | `0x174` | - | `titles/spyro1/core/effect/native_effect_state.cpp` | The `jal` at 0x8004A118 returns to +0x174. |
| `kHeights` | `kBlock` | `0x0` | - | `titles/spyro1/core/effect/shadow_block.h` | eight signed bytes, one per slot |
| `kSlotFlags` | `kBlock` | `0x8` | - | `titles/spyro1/core/effect/shadow_block.h` | eight bytes; any set shrinks the ring |
| `kAnchor` | `kBlock` | `0x10` | - | `titles/spyro1/core/effect/shadow_block.h` | the ground point |
| `kReference` | `kBlock` | `0x18` | - | `titles/spyro1/core/effect/shadow_block.h` | the reference height |
| `kBias` | `kBlock` | `0x1C` | - | `titles/spyro1/core/effect/shadow_block.h` | the depth bias |
| `kRingIndex` | `kBlock` | `0x20` | - | `titles/spyro1/core/effect/shadow_block.h` | the slot the update writes next |
| `kSuppress` | `kBlock` | `0x24` | - | `titles/spyro1/core/effect/shadow_block.h` | positive hides the shadow |
| `kHudMobys` | `kHud` | `0x44` | - | `titles/spyro1/core/frame/draw_motion.h` |  |
| `kInputLatchOpen` | `kGp` | `0x604` | - | `titles/spyro1/core/frame/frame_driver.cpp` |  |
| `kGamestate` | `kGp` | `0x574` | `0x800757D8` | `titles/spyro1/core/guest_globals.h` | g_Gamestate (common.h): the enum the main loop switches on. 0x800757D8 |
| `kCameraPosition` | `kCamera` | `0x28` | `0x80076DF8` | `titles/spyro1/core/guest_globals.h` | 0x80076DF8, m_Position |
| `kCameraOcclusionGroup` | `kCamera` | `0x54` | `0x80076E24` | `titles/spyro1/core/guest_globals.h` | 0x80076E24 |
| `kCameraRotationX` | `kCamera` | `0x4C` | `0x80076E1C` | `titles/spyro1/core/guest_globals.h` | 0x80076E1C |
| `kCameraRotationY` | `kCamera` | `0x4E` | `0x80076E1E` | `titles/spyro1/core/guest_globals.h` | 0x80076E1E |
| `kCameraRotationZ` | `kCamera` | `0x50` | `0x80076E20` | `titles/spyro1/core/guest_globals.h` | 0x80076E20 |
| `kPlayerState` | `kSpyro` | `0x78` | `0x80078AD0` | `titles/spyro1/core/guest_globals.h` | 0x80078AD0 |
| `kPlayerControlFlags` | `kSpyro` | `0x1F4` | `0x80078C4C` | `titles/spyro1/core/guest_globals.h` | 0x80078C4C |
| `kEnvironmentOcclusionGroupCount` | `kEnvironment` | `0xC` | - | `titles/spyro1/core/guest_globals.h` |  |
| `kTitlescreenMode` | `kTitlescreenState` | `0x0` | - | `titles/spyro1/core/guest_globals.h` | m_Mode |
| `kTitlescreenStage` | `kTitlescreenState` | `0x4` | - | `titles/spyro1/core/guest_globals.h` | m_State |
| `kTitlescreenSubTick` | `kTitlescreenState` | `0xC` | - | `titles/spyro1/core/guest_globals.h` | m_SubTick |
| `kTitlescreenSubState` | `kTitlescreenState` | `0x10` | - | `titles/spyro1/core/guest_globals.h` | m_SubState |
| `kTitlescreenDemoType` | `kTitlescreenState` | `0x1C` | - | `titles/spyro1/core/guest_globals.h` | m_DemoType |
| `kCosTable` | `kSinTable` | `0x80` | - | `titles/spyro1/core/guest_globals.h` |  |
| `kSpecularLightDirection` | `kSpecularAndMetal` | `0x0` | - | `titles/spyro1/core/guest_globals.h` |  |
| `kSpecularLightDirectionMoby` | `kSpecularAndMetal` | `0xC` | - | `titles/spyro1/core/guest_globals.h` |  |
| `kMetalMatrix` | `kSpecularAndMetal` | `0x18` | - | `titles/spyro1/core/guest_globals.h` |  |
| `kSpecularTime` | `kSpecularAndMetal` | `0x2C` | - | `titles/spyro1/core/guest_globals.h` |  |
| `kDragonCutsceneState` | `kDragonCutscene` | `0x28` | - | `titles/spyro1/core/guest_globals.h` | m_State |
| `kDragonCutsceneFade` | `kDragonCutscene` | `0x44` | - | `titles/spyro1/core/guest_globals.h` | m_Fade |
| `kDragonCutsceneTicks` | `kDragonCutscene` | `0x3C` | - | `titles/spyro1/core/guest_globals.h` | m_CutsceneTicks |
| `kGemDisplay` | `kHud` | `0x0` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kDragonDisplay` | `kHud` | `0x1` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kLifeDisplay` | `kHud` | `0x2` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kEggDisplay` | `kHud` | `0x3` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kKeyDisplay` | `kHud` | `0x4` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kGemSubState` | `kHud` | `0x5` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kDragonSubState` | `kHud` | `0x6` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kLifeSubState` | `kHud` | `0x7` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kEggSubState` | `kHud` | `0x8` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kKeySubState` | `kHud` | `0x9` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kGemCounter` | `kHud` | `0xC` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` | g_Hud.m_GemSteadyTicks |
| `kDragonCounter` | `kHud` | `0x10` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kLifeCounter` | `kHud` | `0x14` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kEggCounter` | `kHud` | `0x18` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kKeyCounter` | `kHud` | `0x1C` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kTally` | `kHud` | `0x20` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kLifeIndex` | `kHud` | `0x28` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kEggCount` | `kHud` | `0x2C` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kKeyIndex` | `kHud` | `0x30` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kKeyFlag` | `kHud` | `0x34` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kLifeOrbCount` | `kHud` | `0x38` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kSparkTimer` | `kHud` | `0x3C` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kEggPhase` | `kHud` | `0x40` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `kSpriteRect` | `kHud` | `0x4C4` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` | Life rectangles start twelve entries in: `lui 0x8008` - 0x7BF4 + 0x60. |
| `kSpriteValues` | `kLifeOrbCount` | `0x388` | - | `titles/spyro1/core/hud/native_hud_collectables.cpp` | The guest forms the rectangle's source table as the orb count's own address plus 0x388. |
| `kSignedQueue` | `kRenderQueue` | `0x2200` | - | `titles/spyro1/core/moby/native_moby_lists.cpp` |  |
| `kZeroQueue` | `kRenderQueue` | `0x2400` | - | `titles/spyro1/core/moby/native_moby_lists.cpp` |  |
| `kPlayerPreviousPosition` | `kSpyro` | `0x8C` | - | `titles/spyro1/core/player/native_player_physics.cpp` | g_Spyro's own fields this module reads and writes: the previous position, the physics velocity and the two acceleration axes, plus the three 12-bit rotation channels the level entry packs. The channels are named in PACKING order, so channel |
| `kPlayerAccelerationX` | `kSpyro` | `0xF4` | - | `titles/spyro1/core/player/native_player_physics.cpp` |  |
| `kPlayerAccelerationY` | `kSpyro` | `0xF8` | - | `titles/spyro1/core/player/native_player_physics.cpp` |  |
| `kPlayerVelocity` | `kSpyro` | `0x100` | - | `titles/spyro1/core/player/native_player_physics.cpp` |  |
| `kRotationChannel0` | `kSpyro` | `0x124` | `0x80078B7C` | `titles/spyro1/core/player/native_player_physics.cpp` | 0x80078B7C |
| `kRotationChannel1` | `kSpyro` | `0x120` | `0x80078B78` | `titles/spyro1/core/player/native_player_physics.cpp` | 0x80078B78 |
| `kRotationChannel2` | `kSpyro` | `0x11C` | `0x80078B74` | `titles/spyro1/core/player/native_player_physics.cpp` | 0x80078B74 |
| `kRotationChannelSpring0` | `kSpyro` | `0x258` | - | `titles/spyro1/core/player/native_player_physics.cpp` |  |
| `kRotationChannelSpring1` | `kSpyro` | `0x25C` | - | `titles/spyro1/core/player/native_player_physics.cpp` |  |
| `kPackedRotationBytes` | `kSpyro` | `0xC` | - | `titles/spyro1/core/player/native_player_physics.cpp` | The three packed rotation bytes, and the matrices the level entry rebuilds from them: one from those bytes, one from the head-look bytes that follow them, and their product. |
| `kBodyRotationMatrix` | `kPackedRotationBytes` | `0x28` | - | `titles/spyro1/core/player/native_player_physics.cpp` |  |
| `kHeadLookRotationBytes` | `kSpyro` | `0x10` | - | `titles/spyro1/core/player/native_player_physics.cpp` |  |
| `kCombinedRotationMatrix` | `kPackedRotationBytes` | `0x1BC` | - | `titles/spyro1/core/player/native_player_physics.cpp` |  |
| `kLevelEntryFlag` | `kLui7Word` | `0x5944` | `0x80075944` | `titles/spyro1/core/player/native_player_physics.cpp` | 0x80075944 |
| `kObjectListB` | `kLui7Word` | `0x76D8` | `0x800776D8` | `titles/spyro1/core/player/native_player_physics.cpp` | 0x800776D8 |
| `kPlayerStatePrimed` | `kSpyro` | `0x1F0` | - | `titles/spyro1/core/player/native_player_physics.cpp` |  |
| `kFadedColours` | `kWorkBlock` | `0x1100` | - | `titles/spyro1/render/actor_emitter_layout.h` | The faded colour set, and the near detail runs' old words. |
| `kPatchSaves` | `kWorkBlock` | `0x2A00` | - | `titles/spyro1/render/actor_emitter_layout.h` |  |
| `kWorkDepths` | `kWorkBlock` | `0x900` | - | `titles/spyro1/render/actor_emitter_layout.h` |  |
| `kDrawList` | `kWorkBlock` | `0x1600` | - | `titles/spyro1/render/actor_facts.h` | 0x38-byte entries |
| `kSecondaryList` | `kWorkBlock` | `0x2200` | - | `titles/spyro1/render/actor_facts.h` | zero-ended record pointers |
| `kSpriteQueue` | `kWorkBlock` | `0x2400` | - | `titles/spyro1/render/actor_facts.h` | zero-ended record pointers |
| `kShadowList` | `kWorkBlock` | `0x2800` | - | `titles/spyro1/render/actor_facts.h` | (record, byte) pairs |
| `kColourTable` | `kWorkBlock` | `0x2A00` | - | `titles/spyro1/render/actor_facts.h` | The rest of the work block: the sprite queue's lit vertex colours. |
| `kVertexDepths` | `kVertexScreens` | `0x200` | - | `titles/spyro1/render/actor_facts.h` |  |
| `kCameraCopy` | `kVertexScreens` | `0x3E0` | - | `titles/spyro1/render/actor_facts.h` |  |
| `kVertexTable` | `kWorkBlock` | `0x900` | - | `titles/spyro1/render/actor_facts.h` |  |
| `kPartTable` | `kWorkBlock` | `0x1900` | - | `titles/spyro1/render/actor_facts.h` |  |
| `kTintedColours` | `kWorkBlock` | `0x1D00` | - | `titles/spyro1/render/actor_facts.h` |  |
| `kRadii` | `kStaging` | `0x80` | - | `titles/spyro1/render/drop_shadow.cpp` |  |
| `kHeights` | `kStaging` | `0x90` | - | `titles/spyro1/render/drop_shadow.cpp` |  |
| `kRotation` | `kStaging` | `0xC` | - | `titles/spyro1/render/moby_shadows.cpp` |  |
| `kTextureWords` | `kStaging` | `0x20` | - | `titles/spyro1/render/moby_shadows.cpp` |  |
| `kCursor` | `kStaging` | `0x28` | - | `titles/spyro1/render/moby_shadows.cpp` |  |
| `kTable` | `kStaging` | `0x2C` | - | `titles/spyro1/render/moby_shadows.cpp` |  |
| `kPoints` | `kStaging` | `0x30` | - | `titles/spyro1/render/moby_shadows.cpp` | Four rim points and the first again, then their depths. |
| `kClosingPoint` | `kPoints` | `0x10` | - | `titles/spyro1/render/moby_shadows.cpp` |  |
| `kDepths` | `kPoints` | `0x14` | - | `titles/spyro1/render/moby_shadows.cpp` |  |
| `kSpikes` | `kStaging` | `0x24` | - | `titles/spyro1/render/rescue_star.cpp` |  |
| `kShown` | `kBlock` | `0x0` | - | `titles/spyro1/render/rescue_star.h` | nonzero while the star is drawn |
| `kPosition` | `kBlock` | `0x4` | - | `titles/spyro1/render/rescue_star.h` | world x, y, z words |
| `kRotation` | `kBlock` | `0x10` | - | `titles/spyro1/render/rescue_star.h` | Five RT words: its angles under the projection. |
| `kScale` | `kBlock` | `0x24` | - | `titles/spyro1/render/rescue_star.h` |  |
| `kColour` | `kBlock` | `0x2B` | - | `titles/spyro1/render/rescue_star.h` | grey level of every triangle |
| `kFadedColours` | `kSectorList` | `0x2800` | - | `titles/spyro1/render/sky.h` | D_8006FCF4 + 0x2800: where 0x80050240 fades each sector's colour words. |

## Code sites

Addresses inside a function (return addresses, branch joins) the port hooks or reads.

| address | function + offset | port name | port file | meaning |
|---|---|---|---|---|
| `0x80012284` | `main+0x80` | `FrameDrawReturn` | `titles/spyro1/core/frame/frame_draw.cpp` |  |
| `0x800195CC` | `EnqueueHudSprites+0x2CC` | `OrbQuadReturn` | `titles/spyro1/render/hud_anchor.h` | The return addresses of the two rows' calls (jal at 800195C4 and 8001965C). |
| `0x80019664` | `EnqueueHudSprites+0x364` | `EggQuadReturn` | `titles/spyro1/render/hud_anchor.h` |  |
| `0x8001A334` | `LevelTransition_Draw+0x2E4` | `LevelTransitionTail` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x8001BEC8` | `PauseMenu_Draw+0x1ABC` | `LinkReturn` | `titles/spyro1/render/inventory_band.h` | Return address of the band's AddPrimToOT. |
| `0x8001C598` | `PauseMenu_Draw+0x218C` | `MenuFlatten` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x8001C96C` | `MenuTransition_Draw+0x2D8` | `ExitLevelTail` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x8001D31C` | `DragonRescue_Draw+0x340` | `ScaleBlock` | `titles/spyro1/core/frame/dragon_shrink.h` | The scale block's first instruction, after func_8001F158 returns, and where its branches join. |
| `0x8001D438` | `DragonRescue_Draw+0x45C` | `ScaleBlockEnd` | `titles/spyro1/core/frame/dragon_shrink.h` |  |
| `0x8001D644` | `DragonRescue_Draw+0x668` | `DragonTail` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x8001E168` | `SaveLoadMenu_Draw+0xA50` | `FairyTail` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x8001E5E4` | `ActorCutscene_Draw+0x398` | `BalloonistTail` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x8001EA88` | `Cutscene_Draw+0xC0` | `CutsceneFade` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x8001ECA4` | `ReturningHome_Draw+0x124` | `ReturningHomeTail` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x80020009` | `EmitActorDrawList+0x871` | `MagicDivideByVolume` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x8003304C` | `StoryIntro_Update+0x544` | `IntroCardTerminal` | `titles/spyro1/core/frame/transition_skip.cpp` |  |
| `0x80033E68` | `CheckLineOfSightSegment+0x28` | `AfterVecSub` | `titles/spyro1/core/camera/native_camera.cpp` | What each `jal` inside the ray test below wrote into $ra. The segment test spills $ra beside the register file it spills to a global the collision and render paths read, so a host call that left the caller's own $ra there would publish a re |
| `0x80033E74` | `CheckLineOfSightSegment+0x34` | `AfterVecMagnitude` | `titles/spyro1/core/camera/native_camera.cpp` | the `jal` at 0x80033E6C |
| `0x80033E88` | `CheckLineOfSightSegment+0x48` | `AfterVecScale` | `titles/spyro1/core/camera/native_camera.cpp` | the `jal` at 0x80033E80 |
| `0x80033E98` | `CheckLineOfSightSegment+0x58` | `AfterVecCopyStart` | `titles/spyro1/core/camera/native_camera.cpp` | the `jal` at 0x80033E90 |
| `0x80033EB4` | `CheckLineOfSightSegment+0x74` | `AfterVecAdd` | `titles/spyro1/core/camera/native_camera.cpp` | the `jal` at 0x80033EAC |
| `0x80033EC0` | `CheckLineOfSightSegment+0x80` | `AfterSegmentTest` | `titles/spyro1/core/camera/native_camera.cpp` | the `jal` at 0x80033EB8 |
| `0x80033ED4` | `CheckLineOfSightSegment+0x94` | `AfterVecCopyAdvance` | `titles/spyro1/core/camera/native_camera.cpp` | the `jal` at 0x80033ECC |
| `0x80038368` | `ProbeActorGroundHeight+0x28` | `FindGroundHeightBelowReturn` | `titles/spyro1/core/moby/native_moby_transform.cpp` | the `jal`'s own pc + 8 |
| `0x8003E9C8` | `NudgeSpyroFromWallProbes+0xBC` | `SegmentCallReturn` | `titles/spyro1/core/player/native_player_physics.cpp` | The return address `jal kSegmentHitsWorld` at 0x8003E9C0 writes, which the segment test spills as the caller's $ra. |
| `0x80049A08` | `TickSpyroFlameAttack+0x48` | `VecNullBlockedJal` | `titles/spyro1/core/effect/native_effect_state.cpp` | The `jal` each nested call in update_flame_burst stands for (issue 0150): the callee runs with the `$ra` that `jal` leaves, and a call-site audit re-derives every site and its callee from the executable. Two of the callees are reached from  |
| `0x80049AD0` | `TickSpyroFlameAttack+0x110` | `RandArmJal` | `titles/spyro1/core/effect/native_effect_state.cpp` |  |
| `0x80049B18` | `TickSpyroFlameAttack+0x158` | `FillArmJal` | `titles/spyro1/core/effect/native_effect_state.cpp` |  |
| `0x80049CDC` | `TickSpyroFlameAttack+0x31C` | `RandRefreshJal` | `titles/spyro1/core/effect/native_effect_state.cpp` |  |
| `0x80049D24` | `TickSpyroFlameAttack+0x364` | `FillRefreshJal` | `titles/spyro1/core/effect/native_effect_state.cpp` |  |
| `0x80049D60` | `TickSpyroFlameAttack+0x3A0` | `FillResetJal` | `titles/spyro1/core/effect/native_effect_state.cpp` |  |
| `0x80049DBC` | `TickSpyroFlameAttack+0x3FC` | `Zero3Jal` | `titles/spyro1/core/effect/native_effect_state.cpp` | the arm, the reset and the mode-2 arm share it |
| `0x80049DDC` | `TickSpyroFlameAttack+0x41C` | `SmoothHeadLookJal` | `titles/spyro1/core/effect/native_effect_state.cpp` |  |
| `0x80053598` | `AllocEmitListRecord+0x28` | `RandJal` | `titles/spyro1/core/effect/native_particle_alloc.cpp` | Sony's rand(), the standard LCG game/core/native_rand.cpp owns, reached by the `jal` at 0x80053598 in the full-allocation arm. |
| `0x80054BE0` | `UpdateHudCounters+0x258` | `GemStepJal` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x80054BF0` | `UpdateHudCounters+0x268` | `GemSetJal` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x80054D1C` | `UpdateHudCounters+0x394` | `GemPlayJal` | `titles/spyro1/core/hud/native_hud_collectables.cpp` | The `jal` each nested call stands for; several machines share one through a `j`. |
| `0x80054E98` | `UpdateHudCounters+0x510` | `DragonPlayJal` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x80055084` | `UpdateHudCounters+0x6FC` | `LifeStepJal` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x80055098` | `UpdateHudCounters+0x710` | `LifeSetJal` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x8005517C` | `UpdateHudCounters+0x7F4` | `LifePlayJal` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x800553F4` | `UpdateHudCounters+0xA6C` | `EggRuntimeReturn` | `titles/spyro1/core/hud/native_hud_collectables.cpp` | The two `jalr`s through the level's runtime entry return to their own pc + 8. |
| `0x800554A8` | `UpdateHudCounters+0xB20` | `EggFadeJal` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x80055610` | `UpdateHudCounters+0xC88` | `KeyRuntimeReturn` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x80055704` | `UpdateHudCounters+0xD7C` | `KeyPlayJal` | `titles/spyro1/core/hud/native_hud_collectables.cpp` |  |
| `0x80055AE0` | `PlaySoundEffect+0x68` | `ProbeModeJal` | `titles/spyro1/core/audio/native_sound_position.cpp` | The `jal` each nested call stands for (issue 0150): the callee runs with the `$ra` that `jal` leaves, and a call-site audit re-derives every one of these and its callee from the executable. The probe is called from two arms, one per mode, a |
| `0x80055B00` | `PlaySoundEffect+0x88` | `ProbeLimitedModeJal` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x80055B1C` | `PlaySoundEffect+0xA4` | `VsubJal` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x80055B28` | `PlaySoundEffect+0xB0` | `VsraJal` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x80055B34` | `PlaySoundEffect+0xBC` | `VecLenJal` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x80055D3C` | `PlaySoundEffect+0x2C4` | `WrapKindZeroJal` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x80055DA4` | `PlaySoundEffect+0x32C` | `WrapKindOneJal` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x80055E0C` | `PlaySoundEffect+0x394` | `WrapKindTwoJal` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x800560C0` | `PlaySoundEffect+0x648` | `Atan2Jal` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x800560D8` | `PlaySoundEffect+0x660` | `AngDiff8Jal` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x800560FC` | `PlaySoundEffect+0x684` | `PositionalStereoVolumeJal` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |
| `0x8005613C` | `PlaySoundEffect+0x6C4` | `MarkSlotsChangedJal` | `titles/spyro1/core/audio/native_sound_position.cpp` |  |

## Overlay addresses

Addresses in the WAD overlay range; they need the overlay's own config before they enter a map.

| address | port name | port file | meaning |
|---|---|---|---|
| `0x8007B68C` | `FlightResultsDraw` | `titles/spyro1/core/frame/draw_section.cpp` | Flight5, GS_FlightResults through D_8007567C: the same code at the same address in all five flight overlays; like the menus it counts its draws in D_800758B8, opens a later one with PutDrawEnv and ends with DrawOTag(func_80016784(0)) at 0x8 |
| `0x8007BFD0` | `CreditsDraw` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x8007C1F8` | `CreditsFadeReturn` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x8007C260` | `CreditsTail` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x8007CEC8` | `FlightResultsFlatten` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x8007CEE4` | `TitlescreenDraw` | `titles/spyro1/core/frame/draw_section.cpp` | TitlescreenDraw (overlay, 0x8007CEE4) up to its fade: 0x8007DCE8 loads g_Fade, and 0x8007DD04 calls DrawFade with it before the device tail at 0x8007DD0C. |
| `0x8007DCE8` | `TitlescreenFade` | `titles/spyro1/core/frame/draw_section.cpp` |  |
| `0x8007DDE8` | `TitleScreenCopy` | `titles/spyro1/core/hud/native_pause_menu.cpp` |  |
| `0x80200000` | `NativeSharedModelsRamTop` | `titles/spyro1/core/moby/native_shared_models.cpp` | The `lui $s1, 0x8020` every pointer is counted down from, and the offset the model block starts at inside the PETE image — the shared animations are relocated to [peteData + 0x800). |
