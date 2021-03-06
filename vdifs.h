#include <linux/types.h>

struct vdifs_header {
	/* preheader */
	char magic_string[64];
	__le32 img_sig; /* magic number */
	/* note: version is actually stored as a LE 32bit quantity */
	__le16 ver_minor;
	__le16 ver_major;
	
	/* standard header (header size refers to this) */
	__le32 header_bytes;
	__le32 img_type;
	__le32 img_flags;
	char img_desc[32];
	__le32 map_offset;
	__le32 block_offset;
	__le32 cyls, heads, sectors; /* = 0 */
	__le32 sector_size;
	__le32 unused1;
	__le64 disk_bytes;
	/* image block size */
	__le32 block_bytes;
	__le32 block_extra; /* unused extra block data */
	__le32 disk_blocks;
	__le32 allocated_blocks;
};

struct vdifs_sb_info
{
	u_int32_t img_type;
	u_int32_t *blockmap;
	u_int16_t ver_major;
	u_int16_t ver_minor;
	u_int32_t img_flags;
	u_int32_t block_offset;
	u_int32_t map_offset;
	u_int32_t disk_blocks;
};
