/*
 * Remote Processor - Histar ISP remoteproc platform data.
 * include/linux/platform_data/remoteproc-hisi.h
 *
 * Copyright (c) 2013-2014 Hisilicon Technologies CO., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef _PLAT_REMOTEPROC_HISI_ISP_H
#define _PLAT_REMOTEPROC_HISI_ISP_H

struct rproc_ops;
struct platform_device;
struct rproc;

/*
 * struct omap_rproc_pdata - omap remoteproc's platform data
 * @name: the remoteproc's name
 * @oh_name: omap hwmod device
 * @oh_name_opt: optional, secondary omap hwmod device
 * @firmware: name of firmware file to load
 * @mbox_name: name of omap mailbox device to use with this rproc
 * @ops: start/stop rproc handlers
 * @device_enable: omap-specific handler for enabling a device
 * @device_shutdown: omap-specific handler for shutting down a device
 * @set_bootaddr: omap-specific handler for setting the rproc boot address
 */

struct hisi_rproc_data {
    const char *name;
    const char *firmware;
	const char *bootware;
    const char *mbox_name;
    const struct rproc_ops *ops;
    unsigned int ipc_addr;
    int (*device_enable) (struct platform_device *pdev);
    int (*device_shutdown) (struct platform_device *pdev);
    void(*set_bootaddr)(u32);
};

enum a7mappint_type {
    A7BOOT = 0,
    A7TEXT,
    A7DATA,
    A7PGM,
    A7PTE,
    A7RDR,
    A7SHARED,
    A7VQ,
    A7VRING0,
    A7VRING1,
    A7HEAP,
    A7DYNAMIC,
    A7REGISP,
    A7REGIPCS,
    A7REGIPCNS,
    A7REGPCTRL,
    A7REGSCTRL,
    A7REGPCFG,
    A7REGGIC,
    A7REGSYSC,
    A7REGUART,
    A7REGGPIO,
    A7REGGPIO25,
    A7REGIOC,
    MAXA7MAPPING
};

enum hisi_isp_rproc_case_attr {
    DEFAULT_CASE = 0,
    SEC_CASE,
    NONSEC_CASE,
    INVAL_CASE,
};

enum HISP_CLK_TYPE {
    ISP_A7_CLK = 0,
    ISP_FUNC_CLK = 1,
    ISP_I2C_CLK = 2,
    ISP_CLK_MAX
};

extern const struct rproc_fw_ops rproc_elf_fw_ops;
extern const struct rproc_fw_ops rproc_bin_fw_ops;

void hisi_ispsec_share_para_set(void);
int hisi_isp_rproc_case_set(enum hisi_isp_rproc_case_attr);
enum hisi_isp_rproc_case_attr hisi_isp_rproc_case_get(void);
int hisp_powerup(void);
int hisp_powerdn(void);

int hisi_atfisp_cma_alloc(void);
void hisi_atfisp_cma_free(void);
void *hisi_fstcma_alloc(dma_addr_t *dma_handle, size_t size, gfp_t flag);
void hisi_fstcma_free(void *va, dma_addr_t dma_handle, size_t size);

void atfisp_set_nonsec(void);
void atfisp_disreset_a7(unsigned int);
int use_nonsec_isp(void);
int use_sec_isp(void);
unsigned int get_a7sharedmem_addr(void);
void *getsec_a7sharedmem_addr(void);
void *get_a7remap_va(void);
void *get_a7sharedmem_va(void);
void set_a7mem_pa(unsigned int addr);
void set_a7mem_va(void *addr);
void set_a7sharedmem_addr(unsigned int addr);
int hisi_isp_nsec_probe(struct platform_device *pdev);
int hisi_isp_nsec_remove(struct platform_device *pdev);
int hisi_isp_rproc_pgd_set(struct rproc *rproc);
int nonsec_isp_device_enable(void);
int nonsec_isp_device_disable(void);
int hisp_nsec_jpeg_powerup(void);
int hisp_nsec_jpeg_powerdn(void);
int sync_isplogcat(void);
int start_isplogcat(void);
void stop_isplogcat(void);
void set_rpmsg_status(int status);
int is_ispcpu_powerup(void);
void hisp_sendin(void);
void hisp_sendx(void);
void hisp_recvin(void);
void hisp_recvx(void);
void hisp_rpmsgrefs_dump(void);
void hisp_rpmsgrefs_reset(void);
void hisp_recvtask(void);
int hisp_sec_jpeg_powerup(void);
int hisp_sec_jpeg_powerdn(void);
int hisp_jpeg_powerdn(void);
int hisp_jpeg_powerup(void);
int bypass_power_updn(void);
int set_power_updn(int bypass);
extern void hisi_isp_boot_stat_dump(void);
extern u64 hisi_getcurtime(void);
extern size_t print_time(u64 ts, char *buf);
extern unsigned int get_slice_time(void);

#endif /* _PLAT_REMOTEPROC_HISI_ISP_H */

