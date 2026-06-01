
// === Global Offsets (client.dll relative) — 2026-05-27 verified ===
constexpr std::ptrdiff_t dwEntityList                         = 0x21D6878;
constexpr std::ptrdiff_t dwLocalPlayerController              = 0x231D830;
constexpr std::ptrdiff_t dwLocalPlayerPawn                    = 0x231D830;
constexpr std::ptrdiff_t dwViewMatrix                         = 0x2343AB0;
constexpr std::ptrdiff_t dwViewAngles                         = 0x2021A50;
constexpr std::ptrdiff_t dwGlobalVars                         = 0x205E6D0;
constexpr std::ptrdiff_t dwCSGOInput                          = 0x1FD6AA0;
constexpr std::ptrdiff_t dwGameRules                          = 0x1A21D60;
constexpr std::ptrdiff_t dwGlowManager                        = 0x2363580;
constexpr std::ptrdiff_t dwPlantedC4                          = 0x2374278;
constexpr std::ptrdiff_t dwPrediction                        = 0x2090790;
constexpr std::ptrdiff_t dwSensitivity                       = 0x2364098;
constexpr std::ptrdiff_t dwSensitivity_sensitivity            = 0x58;
constexpr std::ptrdiff_t dwViewRender                         = 0x236B4F8;
constexpr std::ptrdiff_t dwWeaponC4                           = 0x22E4518;
constexpr std::ptrdiff_t dwGameEntitySystem_highestEntityIndex = 0x2090;

// === C_BaseEntity ===
constexpr std::ptrdiff_t m_pGameSceneNode  = 0x330;   // CGameSceneNode*
constexpr std::ptrdiff_t m_iHealth         = 0x34C;   // int32
constexpr std::ptrdiff_t m_lifeState       = 0x354;   // uint8 (0=alive)
constexpr std::ptrdiff_t m_iTeamNum        = 0x3EB;   // uint8
constexpr std::ptrdiff_t m_fFlags          = 0x3F8;   // uint32
constexpr std::ptrdiff_t m_flSimulationTime = 0x3B8;  // float32
constexpr std::ptrdiff_t m_hOwnerEntity    = 0x520;   // CHandle

// === CGameSceneNode ===
constexpr std::ptrdiff_t m_vecAbsOrigin    = 0xC8;    // Vector (float x3)

// === CSkeletonInstance === (SDK: inherits CGameSceneNode)
// NOTE: m_modelState=0x150 in SDK but GSN+0x150 is vtable in live!
// Bone access changed: GSN+0x1D0 -> direct bone array (no ModelState intermediate)
constexpr std::ptrdiff_t m_modelState      = 0x150;   // CModelState (SDK value, BROKEN live)

// === CModelState ===
constexpr std::ptrdiff_t m_BoneArray       = 0x80;    // NOT in SDK dump — old offset
constexpr std::ptrdiff_t m_MeshGroupMask   = 0x1C8;   // uint64 (SDK: 0x1C8)

// === Bone Access (LIVE VERIFIED 2026-04-29) ===
constexpr std::ptrdiff_t m_pBoneArray      = 0x1D0;   // GSN+0x1D0 -> direct bone array ptr
// Bone stride = 32 bytes (3 floats pos + 20 bytes pad/rot), world-space

// === CCSPlayerController ===
constexpr std::ptrdiff_t m_hPlayerPawn         = 0x90C;  // CHandle<C_CSPlayerPawn>
constexpr std::ptrdiff_t m_hObserverPawn       = 0x910;  // CHandle<C_CSObserverPawn>
constexpr std::ptrdiff_t m_bPawnIsAlive        = 0x914;  // bool
constexpr std::ptrdiff_t m_sSanitizedPlayerName = 0x860; // CUtlString
constexpr std::ptrdiff_t m_iDesiredFOV         = 0x78C;  // uint32

// === C_BasePlayerPawn ===
constexpr std::ptrdiff_t m_vecViewOffset       = 0xE70;  // CNetworkViewOffsetVector
constexpr std::ptrdiff_t m_pWeaponServices     = 0x11E0; // CPlayer_WeaponServices*
constexpr std::ptrdiff_t m_pObserverServices   = 0x11F8; // CPlayer_ObserverServices*
constexpr std::ptrdiff_t m_pCameraServices     = 0x1218; // CPlayer_CameraServices*

// === C_CSPlayerPawn ===
constexpr std::ptrdiff_t m_pAimPunchServices   = 0x1490;  // AimPunchServices
constexpr std::ptrdiff_t m_iShotsFired         = 0x1C64;  // int32
constexpr std::ptrdiff_t m_iIDEntIndex        = 0x33FC;  // int32 (entity under crosshair for triggerbot)
constexpr std::ptrdiff_t m_angEyeAngles       = 0x3320;  // QAngle (eye angles)
constexpr std::ptrdiff_t m_vecLastClipCameraPos = 0x16DC; // Vector (camera pos)

// === CCSPlayer_AimPunchServices (SDK verified) ===
constexpr std::ptrdiff_t m_aimPunchAngle         = 0x50;   // QAngle (predictableBaseAngle)
constexpr std::ptrdiff_t m_aimPunchAngleVel      = 0x5C;   // QAngle (predictableBaseAngleVel)

// === CPlayer_CameraServices ===
constexpr std::ptrdiff_t m_iFOV                = 0x290;  // uint32
constexpr std::ptrdiff_t m_CurrentFog          = 0x148;  // fogparams_t (on CameraServices)

// === fogparams_t (relative to fogparams base) ===
constexpr std::ptrdiff_t fog_colorPrimary      = 0x14;   // Color (RGBA bytes)
constexpr std::ptrdiff_t fog_colorSecondary    = 0x18;   // Color
constexpr std::ptrdiff_t fog_start             = 0x24;   // float32
constexpr std::ptrdiff_t fog_end               = 0x28;   // float32
constexpr std::ptrdiff_t fog_maxdensity        = 0x30;   // float32
constexpr std::ptrdiff_t fog_enable            = 0x64;   // bool

// === C_EnvSky (on env_sky entity, base is C_BaseModelEntity) ===
constexpr std::ptrdiff_t envsky_vTintColor         = 0xFB9;  // Color
constexpr std::ptrdiff_t envsky_flBrightnessScale  = 0xFC4;  // float32
constexpr std::ptrdiff_t envsky_bEnabled           = 0xFDC;  // bool

// === sky3dparams_t (on pawn at +0x12B8) ===
constexpr std::ptrdiff_t m_skybox3d            = 0x12B8; // sky3dparams_t
constexpr std::ptrdiff_t sky3d_fog             = 0x20;   // fogparams_t within sky3dparams

// === CPlayer_ObserverServices ===
constexpr std::ptrdiff_t m_iObserverMode       = 0x48;   // uint8
constexpr std::ptrdiff_t m_hObserverTarget     = 0x4C;   // CHandle
constexpr std::ptrdiff_t m_flObserverChaseDistance = 0x58; // float32

// === CPlayer_WeaponServices ===
constexpr std::ptrdiff_t m_hMyWeapons          = 0x48;   // CNetworkUtlVector
constexpr std::ptrdiff_t m_hActiveWeapon       = 0x60;   // CHandle

// === C_BaseModelEntity ===
constexpr std::ptrdiff_t m_Glow                = 0xDD8;  // CGlowProperty
constexpr std::ptrdiff_t m_clrRender           = 0xC98;  // Color

// === CGlowProperty ===
constexpr std::ptrdiff_t m_bGlowing            = 0x51;   // bool
constexpr std::ptrdiff_t m_glowColorOverride   = 0x40;   // Color
constexpr std::ptrdiff_t m_iGlowType           = 0x30;   // int32

// === C_BaseEntity Physics ===
constexpr std::ptrdiff_t m_MoveType            = 0x525;   // MoveType_t (uint8: WALK=2,FLY=4,NOCLIP=8)
constexpr std::ptrdiff_t m_vecVelocity         = 0x430;   // CNetworkVelocityVector
constexpr std::ptrdiff_t m_flGravityScale      = 0x540;   // float32 (1.0=normal)
constexpr std::ptrdiff_t m_pMovementServices   = 0x1220;  // CPlayer_MovementServices*

// === C_PlantedC4 ===
constexpr std::ptrdiff_t m_bBombTicking        = 0x1160; // bool
constexpr std::ptrdiff_t m_flC4Blow            = 0x1190; // GameTime_t
constexpr std::ptrdiff_t m_flDefuseCountDown   = 0x11B0; // GameTime_t
constexpr std::ptrdiff_t m_flDefuseLength      = 0x11AC; // float32

// === Entity traversal constants ===
constexpr uintptr_t ENTITY_IDENTITY_SIZE = 0x70;
