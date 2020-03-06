from __future__ import print_function
#! /usr/bin/env cmsRun

import sys
import FWCore.ParameterSet.Config as cms

from Configuration.Geometry.GeometryDD4hepExtended2021_cff import *

process = cms.Process("MaterialAnalyser")

process.source = cms.Source("EmptySource")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)
process.DDDetectorESProducer = cms.ESSource("DDDetectorESProducer",
    confGeomXMLFiles = cms.FileInPath(
        'DetectorDescription/DDCMS/data/cms-geometry-2021.xml'
    ),
    appendToDataLabel = cms.string('CMS')
)


process.DDSpecParRegistryESProducer = cms.ESProducer(
    "DDSpecParRegistryESProducer",
    appendToDataLabel = cms.string('CMS')
)

process.DDCompactViewESProducer = cms.ESProducer(
    "DDCompactViewESProducer",
    appendToDataLabel = cms.string('CMS')
)

process.test = cms.EDAnalyzer(
    "DD4hep_ListGroups",
    DDDetector = cms.ESInputTag('','CMS')
)

process.path = cms.Path(
    process.test
)
