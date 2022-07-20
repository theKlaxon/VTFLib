/*
 * VTFLib
 * Copyright (C) 2005-2011 Neil Jedrzejewski & Ryan Gregg

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later
 * version.
 */

#ifndef VTFLIB_H
#define VTFLIB_H

#ifdef VTFLIB_EXPORTS
#	if defined(_MSC_VER) && !defined(VTFLIB_STATIC)
#		define VTFLIB_API __declspec(dllexport)
#	elif defined(__clang__) || defined(__GNUC__)
#		define VTFLIB_API	__attribute__((visibility("default")))
#	else
#		define VTFLIB_API
#	endif
#else
#	if defined(_WIN32) && !defined(VTFLIB_STATIC)
#		define VTFLIB_API __declspec(dllimport)
#	else
#		define VTFLIB_API
#	endif
#endif

typedef unsigned char	vlBool;
typedef char			vlChar;
typedef unsigned char	vlByte;
typedef signed short	vlShort;
typedef unsigned short	vlUShort;
typedef signed int		vlInt;
typedef unsigned int	vlUInt;
typedef signed long		vlLong;
typedef unsigned long	vlULong;
typedef float			vlSingle;
typedef double			vlDouble;
typedef void			vlVoid;

typedef vlSingle		vlFloat;

#define vlFalse			0
#define vlTrue			1

#define VL_VERSION			200
#define VL_VERSION_STRING	"2.0.0"

#define VTF_MAJOR_VERSION	7
#define VTF_MINOR_VERSION	5

#define VTF_MINOR_VERSION_MIN_SPHERE_MAP	1
#define VTF_MINOR_VERSION_MIN_VOLUME		2

//
// C data types.
//

#ifdef __cplusplus
extern "C" {
#endif

typedef enum tagVTFLibOption
{
	VTFLIB_LUMINANCE_WEIGHT_R,
	VTFLIB_LUMINANCE_WEIGHT_G,
	VTFLIB_LUMINANCE_WEIGHT_B,

	VTFLIB_BLUESCREEN_MASK_R,
	VTFLIB_BLUESCREEN_MASK_G,
	VTFLIB_BLUESCREEN_MASK_B,

	VTFLIB_BLUESCREEN_CLEAR_R,
	VTFLIB_BLUESCREEN_CLEAR_G,
	VTFLIB_BLUESCREEN_CLEAR_B,

	VTFLIB_FP16_HDR_EXPOSURE,

	VTFLIB_VMT_PARSE_MODE
} VTFLibOption;

typedef enum tagVTFImageFormat
{
	IMAGE_FORMAT_RGBA8888 = 0,
	IMAGE_FORMAT_ABGR8888,
	IMAGE_FORMAT_RGB888,
	IMAGE_FORMAT_BGR888,
	IMAGE_FORMAT_RGB565,
	IMAGE_FORMAT_I8,
	IMAGE_FORMAT_IA88,
	IMAGE_FORMAT_P8,
	IMAGE_FORMAT_A8,
	IMAGE_FORMAT_RGB888_BLUESCREEN,
	IMAGE_FORMAT_BGR888_BLUESCREEN,
	IMAGE_FORMAT_ARGB8888,
	IMAGE_FORMAT_BGRA8888,
	IMAGE_FORMAT_DXT1,
	IMAGE_FORMAT_DXT3,
	IMAGE_FORMAT_DXT5,
	IMAGE_FORMAT_BGRX8888,
	IMAGE_FORMAT_BGR565,
	IMAGE_FORMAT_BGRX5551,
	IMAGE_FORMAT_BGRA4444,
	IMAGE_FORMAT_DXT1_ONEBITALPHA,
	IMAGE_FORMAT_BGRA5551,
	IMAGE_FORMAT_UV88,
	IMAGE_FORMAT_UVWQ8888,
	IMAGE_FORMAT_RGBA16161616F,
	IMAGE_FORMAT_RGBA16161616,
	IMAGE_FORMAT_UVLX8888,
	IMAGE_FORMAT_R32F,
	IMAGE_FORMAT_RGB323232F,
	IMAGE_FORMAT_RGBA32323232F,
	IMAGE_FORMAT_NV_DST16,
	IMAGE_FORMAT_NV_DST24,					
	IMAGE_FORMAT_NV_INTZ,
	IMAGE_FORMAT_NV_RAWZ,
	IMAGE_FORMAT_ATI_DST16,
	IMAGE_FORMAT_ATI_DST24,
	IMAGE_FORMAT_NV_NULL,
	IMAGE_FORMAT_ATI2N,						
	IMAGE_FORMAT_ATI1N,
	IMAGE_FORMAT_COUNT,
	IMAGE_FORMAT_NONE = -1
} VTFImageFormat;

typedef enum tagVTFImageFlag
{
	TEXTUREFLAGS_POINTSAMPLE								= 0x00000001,
	TEXTUREFLAGS_TRILINEAR									= 0x00000002,
	TEXTUREFLAGS_CLAMPS										= 0x00000004,
	TEXTUREFLAGS_CLAMPT										= 0x00000008,
	TEXTUREFLAGS_ANISOTROPIC								= 0x00000010,
	TEXTUREFLAGS_HINT_DXT5									= 0x00000020,
	TEXTUREFLAGS_SRGB										= 0x00000040, // Originally internal to VTex as TEXTUREFLAGS_NOCOMPRESS.
	TEXTUREFLAGS_DEPRECATED_NOCOMPRESS						= 0x00000040,
	TEXTUREFLAGS_NORMAL										= 0x00000080,
	TEXTUREFLAGS_NOMIP										= 0x00000100,
	TEXTUREFLAGS_NOLOD										= 0x00000200,
	TEXTUREFLAGS_MINMIP										= 0x00000400,
	TEXTUREFLAGS_PROCEDURAL									= 0x00000800,
	TEXTUREFLAGS_ONEBITALPHA								= 0x00001000, //!< Automatically generated by VTex.
	TEXTUREFLAGS_EIGHTBITALPHA								= 0x00002000, //!< Automatically generated by VTex.
	TEXTUREFLAGS_ENVMAP										= 0x00004000,
	TEXTUREFLAGS_RENDERTARGET								= 0x00008000,
	TEXTUREFLAGS_DEPTHRENDERTARGET							= 0x00010000,
	TEXTUREFLAGS_NODEBUGOVERRIDE							= 0x00020000,
	TEXTUREFLAGS_SINGLECOPY									= 0x00040000,
	TEXTUREFLAGS_UNUSED0									= 0x00080000, //!< Originally internal to VTex as TEXTUREFLAGS_ONEOVERMIPLEVELINALPHA.
	TEXTUREFLAGS_DEPRECATED_ONEOVERMIPLEVELINALPHA			= 0x00080000,
	TEXTUREFLAGS_UNUSED1									= 0x00100000, //!< Originally internal to VTex as TEXTUREFLAGS_PREMULTCOLORBYONEOVERMIPLEVEL.
	TEXTUREFLAGS_DEPRECATED_PREMULTCOLORBYONEOVERMIPLEVEL	= 0x00100000,
	TEXTUREFLAGS_UNUSED2									= 0x00200000, //!< Originally internal to VTex as TEXTUREFLAGS_NORMALTODUDV.
	TEXTUREFLAGS_DEPRECATED_NORMALTODUDV					= 0x00200000,
	TEXTUREFLAGS_UNUSED3									= 0x00400000, //!< Originally internal to VTex as TEXTUREFLAGS_ALPHATESTMIPGENERATION.
	TEXTUREFLAGS_DEPRECATED_ALPHATESTMIPGENERATION			= 0x00400000,
	TEXTUREFLAGS_NODEPTHBUFFER								= 0x00800000,
	TEXTUREFLAGS_UNUSED4									= 0x01000000, //!< Originally internal to VTex as TEXTUREFLAGS_NICEFILTERED.
	TEXTUREFLAGS_DEPRECATED_NICEFILTERED					= 0x01000000,
	TEXTUREFLAGS_CLAMPU										= 0x02000000,
	TEXTUREFLAGS_VERTEXTEXTURE								= 0x04000000,
	TEXTUREFLAGS_SSBUMP										= 0x08000000,
	TEXTUREFLAGS_UNUSED5									= 0x10000000, //!< Originally TEXTUREFLAGS_UNFILTERABLE_OK.
	TEXTUREFLAGS_DEPRECATED_UNFILTERABLE_OK					= 0x10000000,
	TEXTUREFLAGS_BORDER										= 0x20000000,
	TEXTUREFLAGS_DEPRECATED_SPECVAR_RED						= 0x40000000,
	TEXTUREFLAGS_DEPRECATED_SPECVAR_ALPHA					= 0x80000000,
	TEXTUREFLAGS_LAST										= 0x20000000,
	TEXTUREFLAGS_COUNT										= 30
} VTFImageFlag;

// Cubemap face indices
//---------------------
typedef enum tagVTFCubeMapFace
{
	CUBEMAP_FACE_RIGHT = 0,		// +x
	CUBEMAP_FACE_LEFT,			// -x
	CUBEMAP_FACE_BACK,			// +y
	CUBEMAP_FACE_FRONT,			// -y
	CUBEMAP_FACE_UP,			// +z
	CUBEMAP_FACE_DOWN,			// -z
	CUBEMAP_FACE_SPHERE_MAP,		// fall back
	CUBEMAP_FACE_COUNT
} VTFCubeMapFace;

typedef enum tagVTFMipmapFilter
{
	MIPMAP_FILTER_POINT = 0,
	MIPMAP_FILTER_BOX,
	MIPMAP_FILTER_TRIANGLE,
	MIPMAP_FILTER_QUADRATIC,
	MIPMAP_FILTER_CUBIC,
	MIPMAP_FILTER_CATROM,
	MIPMAP_FILTER_MITCHELL,
	MIPMAP_FILTER_GAUSSIAN,
	MIPMAP_FILTER_SINC,
	MIPMAP_FILTER_BESSEL,
	MIPMAP_FILTER_HANNING,
	MIPMAP_FILTER_HAMMING,
	MIPMAP_FILTER_BLACKMAN,
	MIPMAP_FILTER_KAISER,
	MIPMAP_FILTER_COUNT
} VTFMipmapFilter;

typedef enum tagVTFResizeMethod
{
    RESIZE_NEAREST_POWER2 = 0,
    RESIZE_BIGGEST_POWER2,
    RESIZE_SMALLEST_POWER2,
    RESIZE_SET,
	RESIZE_COUNT
} VTFResizeMethod;

#define MAKE_VTF_RSRC_ID(a, b, c) ((vlUInt)(((vlByte)a) | ((vlByte)b << 8) | ((vlByte)c << 16)))
#define MAKE_VTF_RSRC_IDF(a, b, c, d) ((vlUInt)(((vlByte)a) | ((vlByte)b << 8) | ((vlByte)c << 16) | ((vlByte)d << 24)))

typedef enum tagVTFResourceEntryTypeFlag
{
	RSRCF_HAS_NO_DATA_CHUNK = 0x02
} VTFResourceEntryTypeFlag;

typedef enum tagVTFResourceEntryType
{
	VTF_LEGACY_RSRC_LOW_RES_IMAGE = MAKE_VTF_RSRC_ID(0x01, 0, 0),
	VTF_LEGACY_RSRC_IMAGE = MAKE_VTF_RSRC_ID(0x30, 0, 0),
	VTF_RSRC_SHEET = MAKE_VTF_RSRC_ID(0x10, 0, 0),
	VTF_RSRC_CRC = MAKE_VTF_RSRC_IDF('C', 'R', 'C', RSRCF_HAS_NO_DATA_CHUNK),
	VTF_RSRC_TEXTURE_LOD_SETTINGS = MAKE_VTF_RSRC_IDF('L', 'O', 'D', RSRCF_HAS_NO_DATA_CHUNK),
	VTF_RSRC_TEXTURE_SETTINGS_EX = MAKE_VTF_RSRC_IDF('T', 'S', 'O', RSRCF_HAS_NO_DATA_CHUNK),
	VTF_RSRC_KEY_VALUE_DATA = MAKE_VTF_RSRC_ID('K', 'V', 'D'),
	VTF_RSRC_MAX_DICTIONARY_ENTRIES = 32
} VTFResourceEntryType;

typedef enum tagVMTParseMode
{
	PARSE_MODE_STRICT = 0,
	PARSE_MODE_LOOSE,
	PARSE_MODE_COUNT
} VMTParseMode;

typedef enum tagVMTNodeType
{
	NODE_TYPE_GROUP = 0,
	NODE_TYPE_GROUP_END,
	NODE_TYPE_STRING,
	NODE_TYPE_INTEGER,
	NODE_TYPE_SINGLE,
	NODE_TYPE_COUNT
} VMTNodeType;

#pragma pack(1)
typedef struct tagSVTFImageFormatInfo
{
	vlChar *lpName;					//!< Enumeration text equivalent.
	vlUInt	uiBitsPerPixel;			//!< Format bits per pixel.
	vlUInt	uiBytesPerPixel;		//!< Format bytes per pixel.
	vlUInt	uiRedBitsPerPixel;		//!< Format red bits per pixel.  0 for N/A.
	vlUInt	uiGreenBitsPerPixel;	//!< Format green bits per pixel.  0 for N/A.
	vlUInt	uiBlueBitsPerPixel;		//!< Format blue bits per pixel.  0 for N/A.
	vlUInt	uiAlphaBitsPerPixel;	//!< Format alpha bits per pixel.  0 for N/A.
	vlBool	bIsCompressed;			//!< Format is compressed (DXT).
	vlBool	bIsSupported;			//!< Format is supported by VTFLib.
} SVTFImageFormatInfo;
#pragma pack()

#pragma pack(1)
typedef struct tagSVTFCreateOptions
{
	vlUInt uiVersion[2];								//!< Output image version.
	VTFImageFormat ImageFormat;							//!< Output image output storage format.

	vlUInt uiFlags;										//!< Output image header flags.
	vlUInt uiStartFrame;								//!< Output image start frame.
	vlSingle sBumpScale;								//!< Output image bump scale.
	vlSingle sReflectivity[3];							//!< Output image reflectivity. (Only used if bReflectivity is false.)

	vlBool bMipmaps;									//!< Generate MIPmaps. (Space is always allocated.)
	VTFMipmapFilter MipmapFilter;						//!< MIP map re-size filter.

	vlBool bThumbnail;									//!< Generate thumbnail image.
	vlBool bReflectivity;								//!< Compute image reflectivity.

	vlBool bResize;										//!< Resize the input image.
	VTFResizeMethod ResizeMethod;						//!< New size compution method.
	VTFMipmapFilter ResizeFilter;						//!< Re-size filter.
	vlUInt uiResizeWidth;								//!< New width after re-size if method is RESIZE_SET.
	vlUInt uiResizeHeight;								//!< New height after re-size if method is RESIZE_SET.

	vlBool bResizeClamp;								//!< Clamp re-size size.
	vlUInt uiResizeClampWidth;							//!< Maximum width to re-size to.
	vlUInt uiResizeClampHeight;							//!< Maximum height to re-size to.

	vlBool bGammaCorrection;							//!< Gamma correct input image.
	vlSingle sGammaCorrection;							//!< Gamma correction to apply.

	vlBool bSphereMap;									//!< Generate a sphere map for six faced environment maps.
	vlBool bSRGB;										//!< Texture is in the SRGB color space.
} SVTFCreateOptions;

typedef struct tagSVTFTextureLODControlResource
{
	vlByte ResolutionClampU;
	vlByte ResolutionClampV;
	vlByte Padding[2];
} SVTFTextureLODControlResource;
#pragma pack()

typedef enum tagVLProc
{
	PROC_READ_CLOSE = 0,
	PROC_READ_OPEN,
	PROC_READ_READ,
	PROC_READ_SEEK,
	PROC_READ_TELL,
	PROC_READ_SIZE,
	PROC_WRITE_CLOSE,
	PROC_WRITE_OPEN,
	PROC_WRITE_WRITE,
	PROC_WRITE_SEEK,
	PROC_WRITE_SIZE,
	PROC_WRITE_TELL,
	PROC_COUNT
} VLProc;

typedef enum tagVLSeekMode
{
	SEEK_MODE_BEGIN = 0,
	SEEK_MODE_CURRENT,
	SEEK_MODE_END
} VLSeekMode;

typedef vlVoid (*PReadCloseProc)(vlVoid *);
typedef vlBool (*PReadOpenProc)(vlVoid *);
typedef vlUInt (*PReadReadProc)(vlVoid *, vlUInt, vlVoid *);
typedef vlUInt (*PReadSeekProc)(vlLong, VLSeekMode, vlVoid *);
typedef vlUInt (*PReadSizeProc)(vlVoid *);
typedef vlUInt (*PReadTellProc)(vlVoid *);

typedef vlVoid (*PWriteCloseProc)(vlVoid *);
typedef vlBool (*PWriteOpenProc)(vlVoid *);
typedef vlUInt (*PWriteWriteProc)(vlVoid *, vlUInt, vlVoid *);
typedef vlUInt (*PWriteSeekProc)(vlLong, VLSeekMode, vlVoid *);
typedef vlUInt (*PWriteSizeProc)(vlVoid *);
typedef vlUInt (*PWriteTellProc)(vlVoid *);

#ifdef __cplusplus
}
#endif

//
// C library routines.
//

#ifdef __cplusplus
extern "C" {
#endif

//
// VTFLib
//

VTFLIB_API vlUInt vlGetVersion();
VTFLIB_API const vlChar *vlGetVersionString();

VTFLIB_API const vlChar *vlGetLastError();

VTFLIB_API vlBool vlInitialize();
VTFLIB_API vlVoid vlShutdown();

VTFLIB_API vlBool vlGetBoolean(VTFLibOption Option);
VTFLIB_API vlVoid vlSetBoolean(VTFLibOption Option, vlBool bValue);

VTFLIB_API vlInt vlGetInteger(VTFLibOption Option);
VTFLIB_API vlVoid vlSetInteger(VTFLibOption Option, vlInt iValue);

VTFLIB_API vlSingle vlGetFloat(VTFLibOption Option);
VTFLIB_API vlVoid vlSetFloat(VTFLibOption Option, vlSingle sValue);

//
// Proc
//

VTFLIB_API vlVoid vlSetProc(VLProc Proc, vlVoid *pProc);
VTFLIB_API vlVoid *vlGetProc(VLProc Proc);

//
// Memory managment routines.
//

VTFLIB_API vlBool vlImageIsBound();
VTFLIB_API vlBool vlBindImage(vlUInt uiImage);

VTFLIB_API vlBool vlCreateImage(vlUInt *uiImage);
VTFLIB_API vlVoid vlDeleteImage(vlUInt uiImage);

//
// Library routines.  (Basically class wrappers.)
//

VTFLIB_API vlVoid vlImageCreateDefaultCreateStructure(SVTFCreateOptions *VTFCreateOptions);

VTFLIB_API vlBool vlImageCreate(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiFrames, vlUInt uiFaces, vlUInt uiSlices, VTFImageFormat ImageFormat, vlBool bThumbnail, vlBool bMipmaps, vlBool bNullImageData);
VTFLIB_API vlBool vlImageCreateSingle(vlUInt uiWidth, vlUInt uiHeight, vlByte *lpImageDataRGBA8888, SVTFCreateOptions *VTFCreateOptions);
VTFLIB_API vlBool vlImageCreateMultiple(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiFrames, vlUInt uiFaces, vlUInt uiSlices, vlByte **lpImageDataRGBA8888, SVTFCreateOptions *VTFCreateOptions);
VTFLIB_API vlVoid vlImageDestroy();

VTFLIB_API vlBool vlImageIsLoaded();

VTFLIB_API vlBool vlImageLoad(const vlChar *cFileName, vlBool bHeaderOnly);
VTFLIB_API vlBool vlImageLoadLump(const vlVoid *lpData, vlUInt uiBufferSize, vlBool bHeaderOnly);
VTFLIB_API vlBool vlImageLoadProc(vlVoid *pUserData, vlBool bHeaderOnly);

VTFLIB_API vlBool vlImageSave(const vlChar *cFileName);
VTFLIB_API vlBool vlImageSaveLump(vlVoid *lpData, vlUInt uiBufferSize, vlUInt *uiSize);
VTFLIB_API vlBool vlImageSaveProc(vlVoid *pUserData);

//
// Image routines.
//

VTFLIB_API vlUInt vlImageGetHasImage();

VTFLIB_API vlUInt vlImageGetMajorVersion();
VTFLIB_API vlUInt vlImageGetMinorVersion();
VTFLIB_API vlUInt vlImageGetSize();

VTFLIB_API vlUInt vlImageGetWidth();
VTFLIB_API vlUInt vlImageGetHeight();
VTFLIB_API vlUInt vlImageGetDepth();

VTFLIB_API vlUInt vlImageGetFrameCount();
VTFLIB_API vlUInt vlImageGetFaceCount();
VTFLIB_API vlUInt vlImageGetMipmapCount();

VTFLIB_API vlUInt vlImageGetStartFrame();
VTFLIB_API vlVoid vlImageSetStartFrame(vlUInt uiStartFrame);

VTFLIB_API vlUInt vlImageGetFlags();
VTFLIB_API vlVoid vlImageSetFlags(vlUInt uiFlags);

VTFLIB_API vlBool vlImageGetFlag(VTFImageFlag ImageFlag);
VTFLIB_API vlVoid vlImageSetFlag(VTFImageFlag ImageFlag, vlBool bState);

VTFLIB_API vlSingle vlImageGetBumpmapScale();
VTFLIB_API vlVoid vlImageSetBumpmapScale(vlSingle sBumpmapScale);

VTFLIB_API vlVoid vlImageGetReflectivity(vlSingle *sX, vlSingle *sY, vlSingle *sZ);
VTFLIB_API vlVoid vlImageSetReflectivity(vlSingle sX, vlSingle sY, vlSingle sZ);

VTFLIB_API VTFImageFormat vlImageGetFormat();

VTFLIB_API vlByte *vlImageGetData(vlUInt uiFrame, vlUInt uiFace, vlUInt uiSlice, vlUInt uiMipmapLevel);
VTFLIB_API vlVoid vlImageSetData(vlUInt uiFrame, vlUInt uiFace, vlUInt uiSlice, vlUInt uiMipmapLevel, vlByte *lpData);

//
// Thumbnail routines.
//

VTFLIB_API vlBool vlImageGetHasThumbnail();

VTFLIB_API vlUInt vlImageGetThumbnailWidth();
VTFLIB_API vlUInt vlImageGetThumbnailHeight();

VTFLIB_API VTFImageFormat vlImageGetThumbnailFormat();

VTFLIB_API vlByte *vlImageGetThumbnailData();
VTFLIB_API vlVoid vlImageSetThumbnailData(vlByte *lpData);

//
// Resource routines.
//

VTFLIB_API vlBool vlImageGetSupportsResources();

VTFLIB_API vlUInt vlImageGetResourceCount();
VTFLIB_API vlUInt vlImageGetResourceType(vlUInt uiIndex);
VTFLIB_API vlBool vlImageGetHasResource(vlUInt uiType);

VTFLIB_API vlVoid *vlImageGetResourceData(vlUInt uiType, vlUInt *uiSize);
VTFLIB_API vlVoid *vlImageSetResourceData(vlUInt uiType, vlUInt uiSize, vlVoid *lpData);

//
// Helper routines.
//

VTFLIB_API vlBool vlImageGenerateMipmaps(vlUInt uiFace, vlUInt uiFrame, VTFMipmapFilter MipmapFilter);
VTFLIB_API vlBool vlImageGenerateAllMipmaps(VTFMipmapFilter MipmapFilter);

VTFLIB_API vlBool vlImageGenerateThumbnail(vlBool bSRGB);

VTFLIB_API vlBool vlImageGenerateSphereMap();

VTFLIB_API vlBool vlImageComputeReflectivity();

//
// Conversion routines.
//

VTFLIB_API SVTFImageFormatInfo const *vlImageGetImageFormatInfo(VTFImageFormat ImageFormat);
VTFLIB_API vlBool vlImageGetImageFormatInfoEx(VTFImageFormat ImageFormat, SVTFImageFormatInfo *VTFImageFormatInfo);

VTFLIB_API vlUInt vlImageComputeImageSize(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth, vlUInt uiMipmaps, VTFImageFormat ImageFormat);

VTFLIB_API vlUInt vlImageComputeMipmapCount(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth);
VTFLIB_API vlVoid vlImageComputeMipmapDimensions(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth, vlUInt uiMipmapLevel, vlUInt *uiMipmapWidth, vlUInt *uiMipmapHeight, vlUInt *uiMipmapDepth);
VTFLIB_API vlUInt vlImageComputeMipmapSize(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth, vlUInt uiMipmapLevel, VTFImageFormat ImageFormat);

VTFLIB_API vlBool vlImageConvertToRGBA8888(vlByte *lpSource, vlByte *lpDest, vlUInt uiWidth, vlUInt uiHeight, VTFImageFormat SourceFormat);
VTFLIB_API vlBool vlImageConvertFromRGBA8888(vlByte *lpSource, vlByte *lpDest, vlUInt uiWidth, vlUInt uiHeight, VTFImageFormat DestFormat);

VTFLIB_API vlBool vlImageConvert(vlByte *lpSource, vlByte *lpDest, vlUInt uiWidth, vlUInt uiHeight, VTFImageFormat SourceFormat, VTFImageFormat DestFormat);

VTFLIB_API vlBool vlImageResize(vlByte *lpSourceRGBA8888, vlByte *lpDestRGBA8888, vlUInt uiSourceWidth, vlUInt uiSourceHeight, vlUInt uiDestWidth, vlUInt uiDestHeight, VTFMipmapFilter ResizeFilter);

VTFLIB_API vlVoid vlImageCorrectImageGamma(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight, vlSingle sGammaCorrection);
VTFLIB_API vlVoid vlImageComputeImageReflectivity(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight, vlSingle *sX, vlSingle *sY, vlSingle *sZ);

VTFLIB_API vlVoid vlImageFlipImage(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight);
VTFLIB_API vlVoid vlImageMirrorImage(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight);

//
// Memory managment routines.
//

VTFLIB_API vlBool vlMaterialIsBound();
VTFLIB_API vlBool vlBindMaterial(vlUInt uiMaterial);

VTFLIB_API vlBool vlCreateMaterial(vlUInt *uiMaterial);
VTFLIB_API vlVoid vlDeleteMaterial(vlUInt uiMaterial);

//
// Library routines.  (Basically class wrappers.)
//
VTFLIB_API vlBool vlMaterialCreate(const vlChar *cRoot);
VTFLIB_API vlVoid vlMaterialDestroy();

VTFLIB_API vlBool vlMaterialIsLoaded();

VTFLIB_API vlBool vlMaterialLoad(const vlChar *cFileName);
VTFLIB_API vlBool vlMaterialLoadLump(const vlVoid *lpData, vlUInt uiBufferSize);
VTFLIB_API vlBool vlMaterialLoadProc(vlVoid *pUserData);

VTFLIB_API vlBool vlMaterialSave(const vlChar *cFileName);
VTFLIB_API vlBool vlMaterialSaveLump(vlVoid *lpData, vlUInt uiBufferSize, vlUInt *uiSize);
VTFLIB_API vlBool vlMaterialSaveProc(vlVoid *pUserData);

//
// Node routines.
//

VTFLIB_API vlBool vlMaterialGetFirstNode();
VTFLIB_API vlBool vlMaterialGetLastNode();
VTFLIB_API vlBool vlMaterialGetNextNode();
VTFLIB_API vlBool vlMaterialGetPreviousNode();

VTFLIB_API vlBool vlMaterialGetParentNode();
VTFLIB_API vlBool vlMaterialGetChildNode(const vlChar *cName);

VTFLIB_API const vlChar *vlMaterialGetNodeName();
VTFLIB_API vlVoid vlMaterialSetNodeName(const vlChar *cName);

VTFLIB_API VMTNodeType vlMaterialGetNodeType();

VTFLIB_API const vlChar *vlMaterialGetNodeString();
VTFLIB_API vlVoid vlMaterialSetNodeString(const vlChar *cValue);

VTFLIB_API vlUInt vlMaterialGetNodeInteger();
VTFLIB_API vlVoid vlMaterialSetNodeInteger(vlUInt iValue);

VTFLIB_API vlFloat vlMaterialGetNodeSingle();
VTFLIB_API vlVoid vlMaterialSetNodeSingle(vlFloat sValue);

VTFLIB_API vlVoid vlMaterialAddNodeGroup(const vlChar *cName);
VTFLIB_API vlVoid vlMaterialAddNodeString(const vlChar *cName, const vlChar *cValue);
VTFLIB_API vlVoid vlMaterialAddNodeInteger(const vlChar *cName, vlUInt iValue);
VTFLIB_API vlVoid vlMaterialAddNodeSingle(const vlChar *cName, vlFloat sValue);

#ifdef __cplusplus
}
#endif

//
// C++ library routines.
//

#ifdef __cplusplus
namespace VTFLib
{
	namespace IO
	{
		namespace Readers
		{
			class IReader;
		}
		namespace Writers
		{
			class IWriter;
		}
	}
	namespace Nodes
	{
		class CVMTGroupNode;

		//
		// CVMTNode
		//
		class VTFLIB_API CVMTNode
		{
		private:
			vlChar *cName;
			CVMTGroupNode *Parent;

		public:
			CVMTNode(const vlChar *cName);
			virtual ~CVMTNode();

			const vlChar *GetName() const;
			vlVoid SetName(const vlChar *cName);

			CVMTGroupNode *GetParent();

			virtual VMTNodeType GetType() const = 0;
			virtual CVMTNode *Clone() const = 0;
		};

		//
		// CVMTValueNode
		//
		class VTFLIB_API CVMTValueNode : public CVMTNode
		{
		public:
			CVMTValueNode(const vlChar *cName);
			virtual ~CVMTValueNode();

			virtual vlVoid SetValue(const vlChar *cValue) = 0;
		};

		//
		// CVMTStringNode
		//
		class VTFLIB_API CVMTStringNode : public CVMTValueNode
		{
		private:
			vlChar *cValue;

		public:
			CVMTStringNode(const vlChar *cName);
			CVMTStringNode(const vlChar *cName, const vlChar *cValue);
			CVMTStringNode(const CVMTStringNode &StringNode);
			virtual ~CVMTStringNode();

			virtual vlVoid SetValue(const vlChar *cValue);

			const vlChar *GetValue() const;

			virtual VMTNodeType GetType() const;
			virtual CVMTNode *Clone() const;
		};

		//
		// CVMTIntegerNode
		//
		class VTFLIB_API CVMTIntegerNode : public CVMTValueNode
		{
		private:
			vlInt iValue;

		public:
			CVMTIntegerNode(const vlChar *cName);
			CVMTIntegerNode(const vlChar *cName, const vlChar *cValue);
			CVMTIntegerNode(const vlChar *cName, vlInt iValue);
			CVMTIntegerNode(const CVMTIntegerNode &IntegerNode);
			virtual ~CVMTIntegerNode();

			virtual vlVoid SetValue(const vlChar *cValue);

			vlVoid SetValue(vlInt iValue);
			const vlInt GetValue() const;

			virtual VMTNodeType GetType() const;
			virtual CVMTNode *Clone() const;
		};

		//
		// CVMTSingleNode
		//
		class VTFLIB_API CVMTSingleNode : public CVMTValueNode
		{
		private:
			vlFloat fValue;

		public:
			CVMTSingleNode(const vlChar *cName);
			CVMTSingleNode(const vlChar *cName, const vlChar *cValue);
			CVMTSingleNode(const vlChar *cName, vlFloat fValue);
			CVMTSingleNode(const CVMTSingleNode &SingleNode);
			virtual ~CVMTSingleNode();

			virtual vlVoid SetValue(const vlChar *cValue);

			vlVoid SetValue(vlFloat fValue);
			const vlFloat GetValue() const;

			virtual VMTNodeType GetType() const;
			virtual CVMTNode *Clone() const;
		};

		//
		// CVMTGroupNode
		//
		class VTFLIB_API CVMTGroupNode : public CVMTNode
		{
		private:
			class CVMTNodeList;

		private:
			CVMTNodeList *VMTNodeList;

		public:
			CVMTGroupNode(const vlChar *cName);
			CVMTGroupNode(const CVMTGroupNode &GroupNode);
			virtual ~CVMTGroupNode();

			virtual VMTNodeType GetType() const;
			virtual CVMTNode *Clone() const;

		public:
			vlUInt GetNodeCount() const;

			CVMTNode *AddNode(CVMTNode *VMTNode);
			CVMTGroupNode *AddGroupNode(const vlChar *cName);
			CVMTStringNode *AddStringNode(const vlChar *cName, const vlChar *cValue);
			CVMTIntegerNode *AddIntegerNode(const vlChar *cName, vlInt iValue);
			CVMTSingleNode *AddSingleNode(const vlChar *cName, vlFloat fValue);

			vlVoid RemoveNode(CVMTNode *VMTNode);
			vlVoid RemoveAllNodes();

			CVMTNode *GetNode(vlUInt uiIndex) const;
			CVMTNode *GetNode(const vlChar *cName) const;
		};
	}

	//
	// CVTFFile
	//
	struct SVTFHeader;
	class VTFLIB_API CVTFFile
	{
	private:
		SVTFHeader *Header;

		vlUInt uiImageBufferSize;
		vlByte *lpImageData;

		vlUInt uiThumbnailBufferSize;
		vlByte *lpThumbnailImageData;

	public:
		CVTFFile();
		CVTFFile(const CVTFFile &VTFFile);
		CVTFFile(const CVTFFile &VTFFile, VTFImageFormat ImageFormat);

		~CVTFFile();

	public:
		vlBool Create(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiFrames = 1, vlUInt uiFaces = 1, vlUInt uiSlices = 1, VTFImageFormat ImageFormat = IMAGE_FORMAT_RGBA8888, vlBool bThumbnail = vlTrue, vlBool bMipmaps = vlTrue, vlBool bNullImageData = vlFalse);
		vlBool Create(vlUInt uiWidth, vlUInt uiHeight, vlByte *lpImageDataRGBA8888, const SVTFCreateOptions &VTFCreateOptions);
		vlBool Create(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiFrames, vlUInt uiFaces, vlUInt uiSlices, vlByte **lpImageDataRGBA8888, const SVTFCreateOptions &VTFCreateOptions);
		vlVoid Destroy();

		vlBool IsLoaded() const;

		vlBool Load(const vlChar *cFileName, vlBool bHeaderOnly = vlFalse);
		vlBool Load(const vlVoid *lpData, vlUInt uiBufferSize, vlBool bHeaderOnly = vlFalse);
		vlBool Load(vlVoid *pUserData, vlBool bHeaderOnly = vlFalse);

		vlBool Save(const vlChar *cFileName) const;
		vlBool Save(vlVoid *lpData, vlUInt uiBufferSize, vlUInt &uiSize) const;
		vlBool Save(vlVoid *pUserData) const;

	private:
		vlBool IsPowerOfTwo(vlUInt uiSize);
		vlUInt NextPowerOfTwo(vlUInt uiSize);

		vlVoid ComputeResources();

		vlBool Load(IO::Readers::IReader *Reader, vlBool bHeaderOnly);
		vlBool Save(IO::Writers::IWriter *Writer) const;

	public:
		vlBool GetHasImage() const;

		vlUInt GetMajorVersion() const;
		vlUInt GetMinorVersion() const;
		vlUInt GetSize() const;

		vlUInt GetWidth() const;
		vlUInt GetHeight() const;
		vlUInt GetDepth() const;

		vlUInt GetFrameCount() const;
		vlUInt GetFaceCount() const;
		vlUInt GetMipmapCount() const;

		vlUInt GetStartFrame() const;
		vlVoid SetStartFrame(vlUInt uiStartFrame);

		vlUInt GetFlags() const;
		vlVoid SetFlags(vlUInt uiFlags);

		vlBool GetFlag(VTFImageFlag ImageFlag) const;
		vlVoid SetFlag(VTFImageFlag ImageFlag, vlBool bState);

		vlSingle GetBumpmapScale() const;
		vlVoid SetBumpmapScale(vlSingle sBumpmapScale);

		vlVoid GetReflectivity(vlSingle &sX, vlSingle &sY, vlSingle &sZ) const;
		vlVoid SetReflectivity(vlSingle sX, vlSingle sY, vlSingle sZ);

		VTFImageFormat GetFormat() const;
		
		vlByte *GetData(vlUInt uiFrame, vlUInt uiFace, vlUInt uiSlice, vlUInt uiMipmapLevel) const;
		vlVoid SetData(vlUInt uiFrame, vlUInt uiFace, vlUInt uiSlice, vlUInt uiMipmapLevel, vlByte *lpData);

	public:
		vlBool GetHasThumbnail() const;

		vlUInt GetThumbnailWidth() const;
		vlUInt GetThumbnailHeight() const;

		VTFImageFormat GetThumbnailFormat() const;

		vlByte *GetThumbnailData() const;
		vlVoid SetThumbnailData(vlByte *lpData);

	public:
		vlBool GetSupportsResources() const;

		vlUInt GetResourceCount() const;
		vlUInt GetResourceType(vlUInt uiIndex) const;
		vlBool GetHasResource(vlUInt uiType) const;

		vlVoid *GetResourceData(vlUInt uiType, vlUInt &uiSize) const;
		vlVoid *SetResourceData(vlUInt uiType, vlUInt uiSize, vlVoid *lpData);

	public:
		vlBool GenerateMipmaps(VTFMipmapFilter MipmapFilter, vlBool bSRGB);
		vlBool GenerateMipmaps(vlUInt uiFace, vlUInt uiFrame, VTFMipmapFilter MipmapFilter, vlBool bSRGB);

		vlBool GenerateThumbnail(vlBool bSRGB);

		vlBool GenerateSphereMap();

	public:
		vlBool ComputeReflectivity();
	
	public:
		static SVTFImageFormatInfo const &GetImageFormatInfo(VTFImageFormat ImageFormat);

		static vlUInt ComputeImageSize(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth, VTFImageFormat ImageFormat);
		static vlUInt ComputeImageSize(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth, vlUInt uiMipmaps, VTFImageFormat ImageFormat);

		static vlUInt ComputeMipmapCount(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth);
		static vlVoid ComputeMipmapDimensions(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth, vlUInt uiMipmapLevel, vlUInt &uiMipmapWidth, vlUInt &uiMipmapHeight, vlUInt &uiMipmapDepth);
		static vlUInt ComputeMipmapSize(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth, vlUInt uiMipmapLevel, VTFImageFormat ImageFormat);

	private:
		vlUInt ComputeDataOffset(vlUInt uiFrame, vlUInt uiFace, vlUInt uiSlice, vlUInt uiMipmapLevel, VTFImageFormat ImageFormat) const;

	public:
		static vlBool ConvertToRGBA8888(vlByte *lpSource, vlByte *lpDest, vlUInt uiWidth, vlUInt uiHeight, VTFImageFormat SourceFormat);
		static vlBool ConvertFromRGBA8888(vlByte *lpSource, vlByte *lpDest, vlUInt uiWidth, vlUInt uiHeight, VTFImageFormat DestFormat);
		static vlBool Convert(vlByte *lpSource, vlByte *lpDest, vlUInt uiWidth, vlUInt uiHeight, VTFImageFormat SourceFormat, VTFImageFormat DestFormat);

		static vlBool Resize(vlByte *lpSourceRGBA8888, vlByte *lpDestRGBA8888, vlUInt uiSourceWidth, vlUInt uiSourceHeight, vlUInt uiDestWidth, vlUInt uiDestHeight, VTFMipmapFilter ResizeFilter, vlBool bSRGB);

	private:
		static vlBool DecompressDXT1(vlByte *src, vlByte *dst, vlUInt uiWidth, vlUInt uiHeight);
		static vlBool DecompressDXT3(vlByte *src, vlByte *dst, vlUInt uiWidth, vlUInt uiHeight);
		static vlBool DecompressDXT5(vlByte *src, vlByte *dst, vlUInt uiWidth, vlUInt uiHeight);

		static vlBool CompressDXTn(vlByte *lpSource, vlByte *lpDest, vlUInt uiWidth, vlUInt uiHeight, VTFImageFormat DestFormat);

	public:
		static vlVoid CorrectImageGamma(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight, vlSingle sGammaCorrection);

		static vlVoid ComputeImageReflectivity(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight, vlSingle &sX, vlSingle &sY, vlSingle &sZ);

		static vlVoid FlipImage(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight);
		static vlVoid MirrorImage(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight);
	};

	//
	// CVMTFile
	//
	class VTFLIB_API CVMTFile
	{
	private:
		Nodes::CVMTGroupNode *Root;

	public:
		CVMTFile();
		CVMTFile(const CVMTFile &VMTFile);
		~CVMTFile();

	public:
		vlBool Create(const vlChar *cRoot);
		vlVoid Destroy();

		vlBool IsLoaded() const;

		vlBool Load(const vlChar *cFileName);
		vlBool Load(const vlVoid *lpData, vlUInt uiBufferSize);
		vlBool Load(vlVoid *pUserData);

		vlBool Save(const vlChar *cFileName) const;
		vlBool Save(vlVoid *lpData, vlUInt uiBufferSize, vlUInt &uiSize) const;
		vlBool Save(vlVoid *pUserData) const;

	private:
		vlBool Load(IO::Readers::IReader *Reader);
		vlBool Save(IO::Writers::IWriter *Writer) const;

		//Nodes::CVMTNode *Load(IO::Readers::IReader *Reader, vlBool bInGroup);

		vlVoid Indent(IO::Writers::IWriter *Writer, vlUInt uiLevel) const;
		vlVoid Save(IO::Writers::IWriter *Writer, Nodes::CVMTNode *Node, vlUInt uiLevel = 0) const;

	public:
		Nodes::CVMTGroupNode *GetRoot() const;
	};
}
#endif

#endif
