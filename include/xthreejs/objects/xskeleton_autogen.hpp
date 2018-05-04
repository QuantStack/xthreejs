#ifndef XTHREE_SKELETON_HPP
#define XTHREE_SKELETON_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // skeleton declaration
    //

    template<class D>
    class xskeleton : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::vector<xw::xholder<xthree_widget>>, derived_type, bones, std::vector<xw::xholder<xthree_widget>>({}));


    protected:

        xskeleton();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using skeleton = xw::xmaterialize<xskeleton>;

    using skeleton_generator = xw::xgenerator<xskeleton>;

    //
    // skeleton implementation
    //


    template <class D>
    inline void xskeleton<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(bones, state, buffers);
    }

    template <class D>
    inline void xskeleton<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(bones, patch, buffers);
    }

    template <class D>
    inline xskeleton<D>::xskeleton()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xskeleton<D>::set_defaults()
    {
        this->_model_name() = "SkeletonModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xskeleton));
//}
#endif