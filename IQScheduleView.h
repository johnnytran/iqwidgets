//
//  IQScheduleView.h
//  IQWidgets for iOS
//
//  Copyright 2011 EvolvIQ
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <UIKit/UIKit.h>

@protocol IQCalendarDataSource;

@class IQScheduleBlockView;
@class IQScheduleDayView;

#define kIQScheduleViewMaxDays 7

@interface IQScheduleView : UIView {
    id<IQCalendarDataSource> dataSource;
    NSDate* startDate;
    int numDays;
    UILabel* cornerHeader;
    UILabel* dayHeaders[kIQScheduleViewMaxDays];
    UIScrollView* calendarArea;
    IQScheduleDayView* days[kIQScheduleViewMaxDays];
    int indices[kIQScheduleViewMaxDays];
    NSMutableSet* blocks;
    NSMutableSet* timeLabels;
    UIView* nowTimeIndicator;
    NSCalendar* calendar;
    BOOL dirty;
    NSDateFormatter* cornerFormatter;
}

//typedef UIView* (^CellDataPopulator)(NSUInteger index, UITableViewCell* cell);

@property (nonatomic, retain) id<IQCalendarDataSource> dataSource;
@property (nonatomic, retain) NSCalendar* calendar;

@property (nonatomic, readonly) NSDate* startDate;
@property (nonatomic, readonly) NSDate* endDate;
@property (nonatomic, readonly) int numberOfDays;

- (void) setStartDate:(NSDate*)startDate numberOfDays:(int)numberOfDays;

/**
 Sets the scale to show the specified time interval, including the whole days
 of both endpoints.
 */
- (void) setStartDate:(NSDate*)startDate endDate:(NSDate*)endDate;

- (void) setWeekWithDate:(NSDate*)dayInWeek workdays:(BOOL)workdays;

@end


@interface IQScheduleBlockView : UIView {
@private
}
@end
