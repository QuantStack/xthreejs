#ifndef XTHREE_ANIMATION_CLIP_HPP
#define XTHREE_ANIMATION_CLIP_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // animation_clip declaration
    //

    template<class D>
    class xanimation_clip : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<std::string>, derived_type, name);
        XPROPERTY(double, derived_type, duration, -1);
        XPROPERTY(std::vector<xw::xholder<xthree_widget>>, derived_type, tracks, std::vector<xw::xholder<xthree_widget>>({}));

    protected:

        xanimation_clip();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using animation_clip = xw::xmaterialize<xanimation_clip>;

    using animation_clip_generator = xw::xgenerator<xanimation_clip>;

    //
    // animation_clip implementation
    //

    template <class D>
    inline void xanimation_clip<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(name, state, buffers);
        xw::set_patch_from_property(duration, state, buffers);
        xw::set_patch_from_property(tracks, state, buffers);
    }

    template <class D>
    inline void xanimation_clip<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(name, patch, buffers);
        xw::set_property_from_patch(duration, patch, buffers);
        xw::set_property_from_patch(tracks, patch, buffers);
    }

    template <class D>
    inline xanimation_clip<D>::xanimation_clip()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xanimation_clip<D>::set_defaults()
    {
        this->_model_name() = "AnimationClipModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xanimation_clip));
//}
#endif